/*
 * Config.cpp
 *
 *  Created on: 25 Apr 2014
 *      Author: Chris
 */

#include "Config.h"
#include "Defaults.h"

#include <arduinolib\EEPROM\EEPROM.h>

CConfig::CConfig() {
	// Set Configuration to default values
	m_nSerialBaudRate = DEFAULT_BAUD;
}

CConfig::~CConfig() {
	// TODO Auto-generated destructor stub
}

int CConfig::ReadEEPROMBuffer(int &nAddr, void *pDest, size_t len)
{
	size_t n;
	for (n=0; n<len; n++)
		*(((uint8_t*)pDest)+n)=EEPROM.read(nAddr+n);

	nAddr += len;
	return (int)len;
}

void CConfig::RetrieveSettings()
{
	//	Retrieve settings from EEPROM
	int i=0;
	int nVer;
	ReadEEPROMBuffer(i, &nVer, sizeof(nVer));

	if(nVer == CONFIG_VER)
	{
		ReadEEPROMBuffer(i,&m_nSerialBaudRate,sizeof(m_nSerialBaudRate));
	}
}
