#ifndef GARMINFILEBASEDDEVICE_H_INCLUDED
#define GARMINFILEBASEDDEVICE_H_INCLUDED

#define TIXML_USE_TICPP
#include "ticpp.h"
#include <string>
#include <list>
#include <iostream>
#include <fstream>
#include "messageBox.h"
#include "gpsDevice.h"
#include "log.h"

using namespace std;

class MessageBox;



class GarminFilebasedDevice : public GpsDevice
{
public:
    GarminFilebasedDevice();

    virtual ~GarminFilebasedDevice();

    void setDeviceDescription(TiXmlDocument * device);

  /**
   * Returns the device description in XML format to be passed to the Garmin Javascript Libs
   * @return xml string with device description
   */
    string getDeviceDescription() const;

  /**
   * Starts a thread that writes the passed xml string to the given filename
   * @param filename - filename on disk
   * @param xml - content for the file on disk
   * @return int returns 1 if successful otherwise 0
   */
    int startWriteToGps(string filename, string xml);

  /**
   * Sets the path on disk where the device is mounted
   * @param directory full path to a directory on disk
   */
    virtual void setBaseDirectory(string directory);

  /**
   * Sets a command that gets executed after the file was stored on disk
   * @param cmd command to execute after the file was stored on disk
   */
    virtual void setStorageCommand(string cmd);

  /**
   * Returns true if the device is available - current implementation checks if directory exists
   * @return true if devices should be shown to user
   */
    virtual bool isDeviceAvailable();


  /**
   * Starts reading the FIT data directory
   */
    virtual int startReadFITDirectory();

  /**
   * Checks if the read of the FIT data directory finished
   * @return 0 = idle 1 = working 2 = waiting 3 = finished
   */
    virtual int finishReadFITDirectory();

  /**
   * Cancels reading the FIT data directory
   */
    virtual void cancelReadFITDirectory();

    /**
     * Gets the FIT data xml
     * @return xml containing FIT directory data read from garmin device
     */
    virtual string getFITData();

  /**
   * Starts reading the fitness data without points
   */
    virtual int startReadFitnessDirectory();

  /**
   * Checks if the read of the fitness directory finished
   * @return 0 = idle 1 = working 2 = waiting 3 = finished
   */
    virtual int finishReadFitnessDirectory();

    /**
     * Cancels the read of the fitness data
     */
    virtual void cancelReadFitnessData();

    virtual int startReadFitnessDetail(string id);

    virtual int finishReadFitnessDetail();

    virtual void cancelReadFitnessDetail();

    virtual string getGpxData();

    /**
     * Start the reading of a file in the GPX format (like current.gpx on Oregon)
     */
    virtual int startReadFromGps();
    /**
     * This is used to indicate the status of the read process.
     * @return 0 = idle 1 = working 2 = waiting 3 = finished
     */
    virtual int finishReadFromGps();
    /**
     * Cancels the current read from the device.
     */
    virtual void cancelReadFromGps();

    /**
     * Returns a file from the device
     */
    virtual string getBinaryFile(string relativeFilePath);

    /**
     * Starts a binary file write to the device
     * @return number of downloads found in data
     */
    virtual int startDownloadData(string gpsDataString);

    /**
     * Retrieves the next download url
     * @return url to download
     */
    virtual string getNextDownloadDataUrl();

    /**
     * Writes some bytes into the file opened by startDownloadData
     * @return Bytes written to file
     */
    virtual int writeDownloadData(char *, int length);

    /**
     * This is used to indicate the status of the write download data process.
     * @return 0 = idle 1 = working 2 = waiting 3 = finished
     */
    virtual int finishDownloadData();

    /**
     * Saves/Closes the current file
     */
    virtual void saveDownloadData();

    /**
     * Cancels the current file download
     */
    virtual void cancelDownloadData();

  /**
   * Starts a thread that writes the passed xml string to the given filename
   * @param filename - filename on disk
   * @param data - the filename to write to on the device.
   * @param dataTypeName - a Fitness DataType from the GarminDevice.xml retrieved with DeviceDescription
   * @return int returns 1 if successful otherwise 0
   */
    virtual int startWriteFitnessData(string filename, string data, string dataTypeName);

    /**
     * This is used to indicate the status of the write fitness data process.
     * @return 0 = idle 1 = working 2 = waiting 3 = finished
     */
    virtual int finishWriteFitnessData();

    /**
     * Cancels the current write of fitness data
     */
    virtual void cancelWriteFitnessData();

    /**
     * Returns the bytes available in the given path on the device
     * @return bytes available (-1 for non-mass storage mode devices.)
     */
    virtual int bytesAvailable(string path);

protected:

  /**
   * Returns a message for the user. Should be called if finishWriteToGps returns 2 (waiting)
   * The function that fetches the message must delete the message!
   * @return MessageBox for the user to display
   */
    virtual MessageBox * getMessage();

  /**
   * A message can be answered by the user. This function must be called if the message was answered
   * @param answer contains the button the user pressed
   */
    virtual void userAnswered(const int answer);

  /**
   * Cancels the write thread
   */
    virtual void cancelWriteToGps();

  /**
   * Returns if the transfer to the device was successful
   * @return int     0 = failed    1 = success
   */
    virtual int getTransferSucceeded();


    TiXmlDocument * deviceDescription;


  /**
   * Returns the status if writing to device is finished
   * @return int     0 = idle    1 = working    2 = waiting    3 = finished
   */
    virtual int finishWriteToGps();



    virtual void doWork();

    void writeGpxFile();

  /**
   * Directory where this device is mounted in the file system
   */
    string baseDirectory;

    /**
     * Directory where the device stores it's gpx files
     */
    string gpxDirectory;

    string gpxFileExtension;

  /**
   * Command that should be executed after file was written. Leave empty if no command should be executed
   */
    string storageCmd;

  /**
   * File content to write to disk
   */
    string xmlToWrite;

  /**
   * File name for file on disk
   */
    string filenameToWrite;

  /**
   * The thread can create a message for the user - this message is stored here
   */
    MessageBox *  waitingMessage;

  /**
   * If an overwrite yes/no message is posted to the user, this variable is set to 1 if the user wishes to overwrite the file. Otherwise set to 0
   */
    int overwriteFile;

  /**
   * The thread stores the success state in this variable
   */
  bool transferSuccessful;

  virtual void setPathesFromConfiguration();

  /**
   * File where this device stores its fitness/gpx data
   */
  string fitnessFile;

  /**
   * Contains the device id
   */
   string deviceId;

    /**
     * Is used to store the data given by startDownloadData()
     */
   typedef struct _DeviceDownloadData {
        string url;          /**< URL to download */
        string destination;  /**< Local path to store url */
        string regionId;     /**< RegionId - unknown purpose */
   } DeviceDownloadData;

    /**
     * stores a list of files to download and store on the device (provided by startDownloadData())
     */
   list <DeviceDownloadData> deviceDownloadList;

    /**
     * File hande for downloadData
     */
   ofstream downloadDataOutputStream;

    /**
     * Counts errors during file download to the device
     */
   int downloadDataErrorCount;

    typedef struct _MassStorageDirectoryType {
        string path;
        string name;
        bool writeable;
        bool readable;
    } MassStorageDirectoryType;

    /**
     * Contains a list of directories available on device (read from garmindevice.xml)
     */
   list <MassStorageDirectoryType> deviceDirectories;


};

#endif // GARMINFILEBASEDDEVICE_H_INCLUDED
