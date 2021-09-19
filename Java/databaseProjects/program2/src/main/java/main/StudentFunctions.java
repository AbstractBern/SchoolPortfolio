package main;

import com.sun.source.tree.NewArrayTree;
import hashdb.HashFile;
import hashdb.HashHeader;
import hashdb.Vehicle;
import misc.MutableInteger;
import misc.ReturnCodes;

import java.io.*;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Arrays;
public class StudentFunctions {
    public static boolean matchThis(String oldId, String newId) {
        Boolean isGood = true;
        for (int x= 0; x<newId.length(); x++) {
            if (oldId.charAt(x) != newId.charAt(x) ){
                isGood = false;
                break;
            }
        }
        return isGood;
    }
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
        MutableInteger rbn = new MutableInteger(P2Main.hash(vehicle.getVehicleId(), hashFile.getHashHeader().getMaxHash()));
        Vehicle tmp = vehicle;

        int num = readRec(hashFile,rbn,tmp);
        Vehicle redo = vehicle;
        boolean value = matchThis(vehicle.getVehicleIdAsString(),tmp.getVehicleIdAsString());
        if ( num == ReturnCodes.RC_LOC_NOT_FOUND || tmp.getVehicleId()[0] == '\0' || tmp.getVehicleIdAsString().isEmpty() ) {
            writeRec(hashFile,rbn,redo);
        } else if ( value ) {
            return ReturnCodes.RC_REC_EXISTS;
        } else {
            for (int probe = 1; probe < hashFile.getHashHeader().getMaxProbe(); probe++) {
                int var = rbn.intValue();
                var += probe;
                rbn.set(var);
                Vehicle newV = vehicle;
                int ret = readRec(hashFile, rbn, newV);
                value = matchThis(vehicle.getVehicleIdAsString(),newV.getVehicleIdAsString());
                if ( value ) {
                    return ReturnCodes.RC_REC_EXISTS;
                } else if ( newV.getVehicleId()[0] != '\0' && probe == 4 ){
                    System.out.print("****ERROR: Collision\n");
                    return ReturnCodes.RC_TOO_MANY_COLLISIONS;
                } else if ( !value && newV.getVehicleId()[0] == '\0' ) {
                    System.out.println("WRITE TO FILE\n");
                    writeRec(hashFile,rbn,vehicle);
                }
            }
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
    public static int readRec(HashFile hashFile, MutableInteger rbn, Vehicle vehicle) {
        try {
            RandomAccessFile toStore = new RandomAccessFile("vehicle.dat", "rw");
            long RBA = (long) rbn.intValue() * hashFile.getHashHeader().getRecSize();
            if (RBA > toStore.length() ) {
                return ReturnCodes.RC_LOC_NOT_FOUND;
            }
            toStore.seek(RBA);
            byte[] data = new byte[(int)hashFile.getHashHeader().getRecSize()];
            toStore.read(data,0,hashFile.getHashHeader().getRecSize()-1);

            Vehicle newAuto = vehicle;
            newAuto.fromByteArray(data);
            if (!matchThis(vehicle.getVehicleIdAsString(),newAuto.getVehicleIdAsString())) {
                return ReturnCodes.RC_LOC_NOT_FOUND;
            } else {
                vehicle = newAuto;
            }

        } catch (IOException e) {
            e.printStackTrace();
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
    public static int writeRec(HashFile hashFile, MutableInteger rbn, Vehicle vehicle) {
        // open hash-file for raf writing
        try {
            RandomAccessFile toStore = new RandomAccessFile("vehicle.dat","rw");
            long RBA = (long) rbn.intValue() * hashFile.getHashHeader().getRecSize() ;
            toStore.seek(0);
            //System.out.println(vehicle.toString());
            toStore.seek(RBA);
            toStore.write(vehicle.toByteArray(),0,hashFile.getHashHeader().getRecSize()-1);//vehicle.toByteArray(),0,hashFile.getHashHeader().getRecSize());   //are we suppose to write vehicle or hash-header record?
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
        int oldRbn = P2Main.hash(vehicle.getVehicleId(),hashFile.getHashHeader().getMaxHash());
        String oldS = vehicle.getVehicleIdAsString();
        int num = readRec(hashFile, rbn, currVeh);
        String newS = currVeh.getVehicleIdAsString();

        boolean val = matchThis(oldS,newS);
        Vehicle newVeh = vehicle;
        int newRbn = P2Main.hash(currVeh.getVehicleId(),hashFile.getHashHeader().getMaxHash());

        if ( currVeh.getVehicleIdAsString().isEmpty() ) {
            return ReturnCodes.RC_REC_NOT_FOUND;
        }
        if ( num == ReturnCodes.RC_OK ) {
            if (val == true){
                vehicle = currVeh;
            } else {    //is a synonym
                int found = 0;
                for (int probe = 1; probe < hashFile.getHashHeader().getMaxProbe(); probe++) {
                    int var = rbn.intValue();
                    var += probe;
                    rbn.set(var);
                    Vehicle newV = vehicle;
                    oldRbn = P2Main.hash(newVeh.getVehicleId(),hashFile.getHashHeader().getMaxHash());
                    int ret = readRec(hashFile, rbn, newV);
                    val = matchThis(vehicle.getVehicleIdAsString(),newV.getVehicleIdAsString());
                    newRbn = P2Main.hash(newVeh.getVehicleId(),hashFile.getHashHeader().getMaxHash());
                    if (val && oldRbn != newRbn) {
                        vehicle = newV;
                        found = 1;
                    } else if ( rbn.intValue() > hashFile.getHashHeader().getMaxHash()) {
                        return ReturnCodes.RC_REC_NOT_FOUND;
                    } else if (probe == 4 && found == 0) {
                        return ReturnCodes.RC_REC_NOT_FOUND;
                    }
                }
            }
        } else {
            return ReturnCodes.RC_REC_NOT_FOUND;
        }
        //System.out.println("****/vehicleRead - leaving.\n");
        return ReturnCodes.RC_OK;
    }
    public static int vehicleDelete(HashFile hashFile, char[] vehicleId) {
        try {
            Vehicle ins = new Vehicle();
            int p = P2Main.hash(vehicleId,hashFile.getHashHeader().getMaxHash());
            long RBA = (long) p * hashFile.getHashHeader().getRecSize();
            RandomAccessFile toRemove = new RandomAccessFile("vehicle.dat","rw");
            toRemove.seek(RBA);

            toRemove.write(ins.toByteArray());//0,hashFile.getHashHeader().getRecSize());
            toRemove.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return ReturnCodes.RC_OK;
    }

    public static int vehicleUpdate(HashFile hashFile, Vehicle vehicle) {
        MutableInteger spot = new MutableInteger(P2Main.hash(vehicle.getVehicleId(),hashFile.getHashHeader().getMaxHash()));
        int num = readRec(hashFile, spot, vehicle);
        if ( num == ReturnCodes.RC_OK) {
            //old and new both have the same id so we use that to find rbn and rba in writeRec. Delete it and just rewrite it at the same block
            vehicleDelete(hashFile,vehicle.getVehicleId()); //this should work
            writeRec(hashFile,spot,vehicle);
        } else {
            return ReturnCodes.RC_REC_NOT_FOUND;
        }
        /*Note that this function must understand probing.
        NOTE: You can make your life easier with this function if you use MutableInteger and call some of your other functions to help out
        */
        return ReturnCodes.RC_OK;
    }
}
