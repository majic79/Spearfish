/*
 * Config.cpp
 *
 *  Created on: 25 Apr 2014
 *      Author: Chris
 */

#include "Config.h"
#include "Defaults.h"

#include "EEPROM/EEPROM.h"


CConfig::CConfig() :
	m_nSerialBaudRate(DEFAULT_BAUD)
{
	// Set Configuration to default values
}

CConfig::~CConfig()
{
	// Auto-generated destructor stub
	// We shouldn't need to do anything in here as we use this as a static instance for the life of the embedded device
}

//Could probably use the below macro to achieve the same...
//#define ReadWriteEEPROMBuffer(a,b,c,d) ({int n;if(d){n=ReadEEPROMBuffer(a,b,c);}else{n=WriteEEPROMBuffer(a,b,c);} n;})
int CConfig::ReadWriteEEPROMBuffer(int &nAddr, void *pData, size_t len, bool bRead)
{
	int retlen;
	if(bRead != EEPROM_WRITE)
		retlen = ReadEEPROMBuffer(nAddr, pData, len);
	else
		retlen = WriteEEPROMBuffer(nAddr, pData, len);

	return retlen;
}

int CConfig::ReadEEPROMBuffer(int &nAddr, void *pDest, size_t len)
{
	size_t n;
	for (n=0; n<len; n++)
		*(((uint8_t*)pDest)+n)=EEPROM.read(nAddr+n);

	return (int)len;
}

int CConfig::WriteEEPROMBuffer(int &nAddr, void *pDest, size_t len)
{
	size_t n;
	for (n=0; n<len; n++)
		EEPROM.write(nAddr+n, *(((uint8_t*)pDest)+n));

	return (int)len;
}

void CConfig::ReadWriteSettings(bool bRead)
{
	//	Retrieve settings from EEPROM
	int i=0;
	int nVer;

	if(CONFIG_VER == 0)
		bRead = EEPROM_WRITE;

	i+=ReadWriteEEPROMBuffer(i, &nVer, sizeof(nVer), bRead);

	if(nVer == CONFIG_VER)
	{
		i+=ReadWriteEEPROMBuffer(i, &m_nSerialBaudRate, sizeof(m_nSerialBaudRate), bRead);
	}
}
