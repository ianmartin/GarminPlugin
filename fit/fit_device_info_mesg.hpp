////////////////////////////////////////////////////////////////////////////////
// The following FIT Protocol software provided may be used with FIT protocol
// devices only and remains the copyrighted property of Dynastream Innovations Inc.
// The software is being provided on an "as-is" basis and as an accommodation,
// and therefore all warranties, representations, or guarantees of any kind
// (whether express, implied or statutory) including, without limitation,
// warranties of merchantability, non-infringement, or fitness for a particular
// purpose, are specifically disclaimed.
//
// Copyright 2008 Dynastream Innovations Inc.
////////////////////////////////////////////////////////////////////////////////
// ****WARNING****  This file is auto-generated!  Do NOT edit this file.
// Profile Version = 1.0Release
// Tag = $Name: AKW1_000 $
////////////////////////////////////////////////////////////////////////////////


#if !defined(FIT_DEVICE_INFO_MESG_HPP)
#define FIT_DEVICE_INFO_MESG_HPP

#include "fit_mesg.hpp"

namespace fit
{

class DeviceInfoMesg : public Mesg
{
   public:
      DeviceInfoMesg(void) : Mesg(Profile::MESG_DEVICE_INFO)
      {
      }

      DeviceInfoMesg(const Mesg &mesg) : Mesg(mesg)
      {
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns timestamp field
      // Units: s
      ///////////////////////////////////////////////////////////////////////
      FIT_DATE_TIME GetTimestamp(void)
      {
         return GetFieldUINT32Value(253);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set timestamp field
      // Units: s
      ///////////////////////////////////////////////////////////////////////
      void SetTimestamp(FIT_DATE_TIME timestamp)
      {
         SetFieldUINT32Value(253, timestamp);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns device_index field
      ///////////////////////////////////////////////////////////////////////
      FIT_DEVICE_INDEX GetDeviceIndex(void)
      {
         return GetFieldUINT8Value(0);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set device_index field
      ///////////////////////////////////////////////////////////////////////
      void SetDeviceIndex(FIT_DEVICE_INDEX deviceIndex)
      {
         SetFieldUINT8Value(0, deviceIndex);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns device_type field
      ///////////////////////////////////////////////////////////////////////
      FIT_DEVICE_TYPE GetDeviceType(void)
      {
         return GetFieldUINT8Value(1);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set device_type field
      ///////////////////////////////////////////////////////////////////////
      void SetDeviceType(FIT_DEVICE_TYPE deviceType)
      {
         SetFieldUINT8Value(1, deviceType);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns manufacturer field
      ///////////////////////////////////////////////////////////////////////
      FIT_MANUFACTURER GetManufacturer(void)
      {
         return GetFieldUINT16Value(2);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set manufacturer field
      ///////////////////////////////////////////////////////////////////////
      void SetManufacturer(FIT_MANUFACTURER manufacturer)
      {
         SetFieldUINT16Value(2, manufacturer);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns serial_number field
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT32Z GetSerialNumber(void)
      {
         return GetFieldUINT32ZValue(3);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set serial_number field
      ///////////////////////////////////////////////////////////////////////
      void SetSerialNumber(FIT_UINT32Z serialNumber)
      {
         SetFieldUINT32ZValue(3, serialNumber);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns product field
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT16 GetProduct(void)
      {
         return GetFieldUINT16Value(4);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set product field
      ///////////////////////////////////////////////////////////////////////
      void SetProduct(FIT_UINT16 product)
      {
         SetFieldUINT16Value(4, product);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns software_version field
      ///////////////////////////////////////////////////////////////////////
      FIT_FLOAT32 GetSoftwareVersion(void)
      {
         return GetFieldFLOAT32Value(5);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set software_version field
      ///////////////////////////////////////////////////////////////////////
      void SetSoftwareVersion(FIT_FLOAT32 softwareVersion)
      {
         SetFieldFLOAT32Value(5, softwareVersion);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns hardware_version field
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT8 GetHardwareVersion(void)
      {
         return GetFieldUINT8Value(6);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set hardware_version field
      ///////////////////////////////////////////////////////////////////////
      void SetHardwareVersion(FIT_UINT8 hardwareVersion)
      {
         SetFieldUINT8Value(6, hardwareVersion);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns cum_operating_time field
      // Units: s
      // Comment: Reset by new battery or charge.
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT32 GetCumOperatingTime(void)
      {
         return GetFieldUINT32Value(7);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set cum_operating_time field
      // Units: s
      // Comment: Reset by new battery or charge.
      ///////////////////////////////////////////////////////////////////////
      void SetCumOperatingTime(FIT_UINT32 cumOperatingTime)
      {
         SetFieldUINT32Value(7, cumOperatingTime);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns battery_voltage field
      // Units: V
      ///////////////////////////////////////////////////////////////////////
      FIT_FLOAT32 GetBatteryVoltage(void)
      {
         return GetFieldFLOAT32Value(10);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set battery_voltage field
      // Units: V
      ///////////////////////////////////////////////////////////////////////
      void SetBatteryVoltage(FIT_FLOAT32 batteryVoltage)
      {
         SetFieldFLOAT32Value(10, batteryVoltage);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns battery_status field
      ///////////////////////////////////////////////////////////////////////
      FIT_BATTERY_STATUS GetBatteryStatus(void)
      {
         return GetFieldUINT8Value(11);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set battery_status field
      ///////////////////////////////////////////////////////////////////////
      void SetBatteryStatus(FIT_BATTERY_STATUS batteryStatus)
      {
         SetFieldUINT8Value(11, batteryStatus);
      }

};

} // namespace fit

#endif // !defined(FIT_DEVICE_INFO_MESG_HPP)
