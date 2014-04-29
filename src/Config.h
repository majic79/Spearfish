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

class CConfig {
public:
	CConfig();
	virtual ~CConfig();
	void RetrieveSettings();
	void StoreSettings();

	//	Baud rate for serial comms
	unsigned long getBaudRate(){return m_nSerialBaudRate;}

private:
	int ReadEEPROMBuffer(int &nAddr, void *pDest, size_t len);

	unsigned long m_nSerialBaudRate;
};

#endif /* CONFIG_H_ */
