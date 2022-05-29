#!/bin/bash
# my functions
Create() {
	echo "Creating a photo item."
	read -p "Choose unique photo number: " photoNumber
	# check while not in data/
	read -p "Name of photo file: " photoName
	loc="$HOME/$photoName.jpg"	
	read -p "Date photo was taken (YYYY MM DD): " year month day
	read -p "Location of photo: " place
	# do while for people names
	read -p "People in photo: " people
	fileName="p$photoNumber.photo"
	touch data/$fileName
	echo -e "$loc\n$year $month $day\n$place\n$people" >> data/$fileName
	echo "Successfully created $fileName in dat dir."
}
Read() {
	echo "Reading a photo item."
	read -p "Which number does your photo contain (pXXX)?: " number
	file="p$number.photo"
	if [ -f "data/$file" ]; then
		cat data/$file
	else
		echo "File does not exist!"
	fi
}
Update() {
	echo "Updating a photo item."
	read -p "What is the # of the photo you want to update?: " number
	count=0
	while read line; do
		echo $line
		if [ $count -eq 0 ]; then
			fileLocation=$line
		elif [ $count -eq 1 ]; then
			newDay=$line
		elif [ $count -eq 2 ]; then
			place=$line
		elif [ $count -eq 3 ]; then
			people=$line
		fi
		let count+=1
	done < "data/p$number.photo"
	read -p "Do you wish to change the file location [Y/N]?: " decision
	case "$decision" in
		[Yy]) read -p "What is the new location?: " newLocation
			change=1
			fileLocation=$newLocation;;
		*) echo -e "Next.\n";;
	esac
	read -p "Do you wish to change the year month and day [Y/N]?: " decision
	case "$decision" in
		[Yy]) read -p "What is the new date [YYYY MM DD]: " newDay
			change=1
			newDay=$newDay;;
		*) echo -e "Next.\n";;
	esac
	read -p "Do you wish to change the place of photo [Y/N]: " decision
	case "$decision" in
		[Yy]) read -p "What is the new place? " newPlace
			change=1
			place=$newPlace;;
		*) echo -e "Next.\n";;
	esac
	read -p "Do you wish to update the people in the photo [Y/N]:  " decision
	case "$decision" in
		[Yy]) read -p "Who do you want to include (comma separated)?: " newPeople
		change=1
			people=$newPeople;;
		*) echo -e "Next.\n";;
	esac
	if [ $change -eq 1 ]; then
		echo -e "$fileLocation\n$newDay\n$place\n$people" > data/p$number.photo
		echo "p$number.photo successfully updated."
	fi
}
Delete() {
	echo "Deleting a photo item."
	read -p "Which number does your photo contain (pXXX)?: " number
	read -p "Do you wish to delete p$number.photo? (Yy/Nn)" decision
	file="p$number.photo"
	case "$decision" in
		[Yy]) echo "Deleting File!"
				rm data/$file;;
		[Nn]) echo "Nevermind!";;
		*) echo "Exiting!"
			exit 0;;
	esac
}

while true; do	
	echo -e "\nEnter one of the following actions or press CTRL-D to exit."
	echo "C - Create a new photo item"
	echo "R - Read an existing photo item"
	echo "U - Update an existing photo item"
	echo "D - Delete an existing photo item"
	echo "Q - Quit"
	read -p "Enter option: " option

	case "$option" in
		[Cc]) echo -e "\n"
				 Create ;;
		[Rr]) echo -e "\n"
				Read ;;
		[Uu]) echo -e "\n"
				Update ;;
		[Dd]) echo -e "\n"
				Delete ;;
		[Qq]) echo "Quitting program. Goodbyte"
				exit 0;;
		*)	echo "Exiting!"	
			break;;
	esac
done
