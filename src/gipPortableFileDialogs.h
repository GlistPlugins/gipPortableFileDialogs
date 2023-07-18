/*
 * gipPortableFileDialogs.cpp
 *
 *  Created on: July 17, 2023
 *      Author: Mehmet Can Gul
 */

#ifndef SRC_GIPPORTABLEFILEDIALOGS_H_
#define SRC_GIPPORTABLEFILEDIALOGS_H_

#include "gBasePlugin.h"
#include <portable-file-dialogs.h>


class gipPortableFileDialogs : public gBasePlugin{
public:
	gipPortableFileDialogs();
	virtual ~gipPortableFileDialogs();

	void setup();

	void notify();
	void message();
	void select_folder();
	void open_file();
	void save_file();
	void api();
};

#endif /* SRC_GIPPORTABLEFILEDIALOGS_H_ */
