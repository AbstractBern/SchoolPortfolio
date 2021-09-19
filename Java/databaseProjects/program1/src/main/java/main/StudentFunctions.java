package main;

import hashdb.HashFile;
import hashdb.HashHeader;
import hashdb.Vehicle;
import misc.MutableInteger;
import misc.ReturnCodes;

import java.io.*;

public class StudentFunctions {
    /**
     * hashCreate
     * This function creates a hash file containing only the HashHeader record.
     * • If the file already exists, return RC_FILE_EXISTS
     * • Create the binary file by opening it.
     * • Write the HashHeader record to the file at RBN 0.
     * • close the file.
     * • return RC_OK.
     */
    public static int hashCreate(String fileName, HashHeader hashHeader) {
        File file = new File(fileName);
        if ( file.exists() ) {
            return ReturnCodes.RC_FILE_EXISTS;
        }
        try {
            FileOutputStream hashFile = new FileOutputStream(file);
            hashFile.write(hashHeader.toByteArray(),0,hashHeader.toByteArray().length);
            hashFile.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return ReturnCodes.RC_OK;
    }

    /**
     * hashOpen
     * This function opens an existing hash file which must contain a HashHeader record
     * , and sets the file member of hashFile
     * It returns the HashHeader record by setting the HashHeader member in hashFile
     * If it doesn't exist, return RC_FILE_NOT_FOUND.
     * Read the HashHeader record from file and return it through the parameter.
     * If the read fails, return RC_HEADER_NOT_FOUND.
     * return RC_OK
     */
    public static int hashOpen(String fileName, HashFile hashFile) {
        File file = new File(fileName);
        if ( !file.exists() ) {
            System.out.print("File not exists in hashCreate\n");
            return ReturnCodes.RC_FILE_NOT_FOUND;
        }
        if ( file.length() == 0 ) {
            System.out.println("****File empty\n");
            return ReturnCodes.RC_HEADER_NOT_FOUND;
        }
        try {   //writing to binary file but not writing to hash file?
            FileInputStream thisFile = new FileInputStream(fileName);
            int length = thisFile.available();
            byte[] data = new byte[(int) length];
            thisFile.read(data,0,length);
            HashHeader newHash = new HashHeader(); // because we technically do not have one to write.
            newHash.fromByteArray(data);
            thisFile.close();
            hashFile.setHashHeader(newHash);
            RandomAccessFile toStore = new RandomAccessFile("vehicle.dat","rw");
            toStore.write(newHash.toByteArray(),0,newHash.toByteArray().length);
            hashFile.setFile(toStore);
        } catch (IOException e) {
            e.printStackTrace();
            System.out.println("****/ERROR!\n");
            return ReturnCodes.RC_HEADER_NOT_FOUND;
        }
        //System.out.println("****hashOpen works!\n");
        return ReturnCodes.RC_OK;
    }

    /**
     * vehicleInsert
     * This function inserts a vehicle into the specified file.
     * Determine the RBN using the Main class' hash function.
     * Use readRec to read the record at that RBN.
     * If that location doesn't exist
     * OR the record at that location has a blank vehicleId (i.e., empty string):
     * THEN Write this new vehicle record at that location using writeRec.
     * If that record exists and that vehicle's szVehicleId matches, return RC_REC_EXISTS.
     * (Do not update it.)
     * Otherwise, return RC_SYNONYM. a SYNONYM is the same thing as a HASH COLLISION
     * Note that in program #2, we will actually insert synonyms.
     */
    public static int vehicleInsert(HashFile hashFile, Vehicle vehicle) {
        int nuim = 0; //rbnPosition = P2Main.hash(vehicle.getVehicleId(), hashFile.getHashHeader().getMaxHash());
        Vehicle tmp = vehicle;
        int num = readRec(hashFile,nuim,tmp);
        if ( num == ReturnCodes.RC_LOC_NOT_FOUND || tmp.getVehicleId()[0] == '\0') {
            writeRec(hashFile,nuim,vehicle);
        } else if ( num == ReturnCodes.RC_OK || tmp.getVehicleId().equals(vehicle.getVehicleId()) ) {
            return ReturnCodes.RC_REC_EXISTS;
        } else {
            //collision
            return ReturnCodes.RC_SYNONYM;
        }
        //System.out.println("***/vehicleInsert - leaving.\n");
        return ReturnCodes.RC_OK;
    }
    /**
     * readRec(
     * This function reads a record at the specified RBN in the specified file.
     * Determine the RBA based on RBN and the HashHeader's recSize
     * Use seek to position the file in that location.
     * Read that record and return it through the vehicle parameter.
     * If the location is not found, return RC_LOC_NOT_FOUND.  Otherwise, return RC_OK.
     * Note: if the location is found, that does NOT imply that a vehicle
     * was written to that location.  Why?
      */
    public static int readRec(HashFile hashFile, int rbn, Vehicle vehicle) {
        try {
            RandomAccessFile toStore = new RandomAccessFile("vehicle.dat", "rw");
            long RBA = 0; //rbn * hashFile.getHashHeader().getRecSize();
            toStore.seek(RBA);
            if (RBA > toStore.length() ) {
                return ReturnCodes.RC_LOC_NOT_FOUND;
            }
            byte[] data = new byte[(int)hashFile.getHashHeader().getRecSize()];
            toStore.readFully(data,0,hashFile.getHashHeader().getRecSize());
            vehicle.fromByteArray(data);
        } catch (IOException e) {
            System.out.print("?EOF_ERROR\n");
            //should catch the positional not existing here
        }
        //System.out.println("****/readRec - leaving.\n");
        return ReturnCodes.RC_OK;
    }

    /**
     * writeRec
     * This function writes a record to the specified RBN in the specified file.
     * Determine the RBA based on RBN and the HashHeader's recSize
     * Use seek to position the file in that location.
     * Write that record to the file.
     * If the write fails, return RC_LOC_NOT_WRITTEN.
     * Otherwise, return RC_OK.
     */
    public static int writeRec(HashFile hashFile, int rbn, Vehicle vehicle) {
        // open hash-file for raf writing
        try {
            RandomAccessFile toStore = new RandomAccessFile("vehicle.dat","rw");
            long RBA =0; //=  (long) rbn * hashFile.getHashHeader().getRecSize();
            toStore.seek(RBA);
            toStore.write(vehicle.toByteArray(),0,hashFile.getHashHeader().getRecSize());   //are we suppose to write vehicle or hash-header record?
            toStore.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.out.println("****/ERROR!\n");
            return ReturnCodes.RC_LOC_NOT_WRITTEN;
        }
        //System.out.println("****writeRec - leaving.\n");
        return ReturnCodes.RC_OK;
    }

    /**
     * vehicleRead
     * This function reads the specified vehicle by its vehicleId.
     * Since the vehicleId was provided,
     * determine the RBN using the Main class' hash function.
     * Use readRec to read the record at that RBN.
     * If the vehicle at that location matches the specified vehicleId,
     * return the vehicle via the parameter and return RC_OK.
     * Otherwise, return RC_REC_NOT_FOUND
     */
    public static int vehicleRead(HashFile hashFile, MutableInteger rbn, Vehicle vehicle) {
        Vehicle currVeh = vehicle;
        int num = readRec(hashFile, rbn, vehicle);
        Vehicle newVeh = vehicle;
        if ( num == ReturnCodes.RC_OK ) {
            if ( currVeh.getVehicleId().equals(newVeh.getVehicleId())) {
                vehicle = newVeh;
            } else {    //is a synonym

            }
        } else {
            System.out.println("****ERROR: Record not found\n");
            return ReturnCodes.RC_REC_NOT_FOUND;
        }
        //System.out.println("****/vehicleRead - leaving.\n");
        return ReturnCodes.RC_OK;
    }
    public static int vehicleDelete(HashFile hashFile, char[] vehicleId) {
        try {
            byte[] b = {'\0'};
            int rbn = P2Main.hash(vehicleId,hashFile.getHashHeader().getMaxHash());
            long RBA = (long) rbn * hashFile.getHashHeader().getRecSize();
            RandomAccessFile toRemove = new RandomAccessFile("vehicle.dat","rw");
            toRemove.seek(RBA);
            toRemove.write(b,0,hashFile.getHashHeader().getRecSize());
            toRemove.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return ReturnCodes.RC_OK;
    }

    public static int vehicleUpdate(HashFile hashFile, Vehicle vehicle) {
        int rbn =  P2Main.hash(vehicle.getVehicleId(), hashFile.getHashHeader().getMaxHash());
        int num = readRec(hashFile, rbn, vehicle);
        if ( num == ReturnCodes.RC_OK) {
            //old and new both have the same id so we use that to find rbn and rba in writeRec. Delete it and just rewrite it at the same block
            vehicleDelete(hashFile,vehicle.getVehicleId()); //this should work
            writeRec(hashFile,rbn,vehicle);
        } else {
            return ReturnCodes.RC_REC_NOT_FOUND;
        }
        /*Note that this function must understand probing.
        NOTE: You can make your life easier with this function if you use MutableInteger and call some of your other functions to help out
        */
        return ReturnCodes.RC_OK;
    }
}
