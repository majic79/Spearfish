/*
 * Config.h
 *
 *  Created on: 25 Apr 2014
 *      Author: Chris
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#include <stdlib.h>

//	Development version...
#define	CONFIG_VER	0x00

#define EEPROM_READ true
#define EEPROM_WRITE false

class CConfig {
public:
	CConfig();
	virtual ~CConfig();
	void ReadWriteSettings(bool bRead);

	//	Baud rate for serial comms
	unsigned long getBaudRate(){return m_nSerialBaudRate;};

private:
	int ReadWriteEEPROMBuffer(int &nAddr, void *pData, size_t len, bool bRead);
	int ReadEEPROMBuffer(int &nAddr, void *pDest, size_t len);
	int WriteEEPROMBuffer(int &nAddr, void *pSource, size_t len);
	unsigned long m_nSerialBaudRate;
	int m_nTempDevices;
	int m_nAxis;
};

#endif /* CONFIG_H_ */
