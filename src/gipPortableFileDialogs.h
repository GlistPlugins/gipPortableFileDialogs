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

	void test_notify();
	void test_message();
	void test_select_folder();
	void test_open_file();
	void test_save_file();
	void test_api();
};

#endif /* SRC_GIPPORTABLEFILEDIALOGS_H_ */
