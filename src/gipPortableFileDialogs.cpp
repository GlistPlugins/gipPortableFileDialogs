/*
 * gipPortableFileDialogs.cpp
 *
 *  Created on: July 17, 2023
 *      Author: Mehmet Can Gul
 */

#include "gipPortableFileDialogs.h"


gipPortableFileDialogs::gipPortableFileDialogs() {
}

gipPortableFileDialogs::~gipPortableFileDialogs() {
}

void gipPortableFileDialogs::setup() {

	   if (!pfd::settings::available())
	    {
	        gLogi() << "Portable File Dialogs are not available on this platform. ";
	    }

	    // Set verbosity to true
	    pfd::settings::verbose(true);
}

void gipPortableFileDialogs::notify() {
    pfd::notify("Important Notification",
                "This is ' a message, pay \" attention \\ to it!",
                pfd::icon::info);

}

void gipPortableFileDialogs::message() {
    auto m = pfd::message("Personal Message",
                          "You are an amazing person, don't do that let anyone make you think otherwise.",
                          pfd::choice::yes_no_cancel,
                          pfd::icon::warning);

    // Optional: do something while waiting for user action
    for (int i = 0; i < 10 && !m.ready(1000); ++i)
    	gLogi() << "Waited 1 second for user input...";

    // Do something according to the selected button
    switch (m.result())
    {
        case pfd::button::yes: gLogi() << "User agreed. "; break;
        case pfd::button::no: gLogi() << "User disagreed. "; break;
        case pfd::button::cancel: gLogi() << "User freaked out. "; break;
        default: break; // Should not happen
    }
}

void gipPortableFileDialogs::selectFolder() {
    auto dir = pfd::select_folder("Select any directory", pfd::path::home()).result();
    gLogi() << "Selected dir: " << dir ;
}

void gipPortableFileDialogs::openFile() {
    auto f = pfd::open_file("Choose files to read", pfd::path::home(),
                            { "Text Files (.txt .text)", "*.txt *.text",
                              "All Files", "*" },
                            pfd::opt::multiselect);
    gLogi() << "Selected files:";
    for (auto const &name : f.result())
        gLogi() << " " + name;
    gLogi() << " ";
}

void gipPortableFileDialogs::saveFile() {
    auto f = pfd::save_file("Choose file to save",
                            pfd::path::home() + pfd::path::separator() + "readme.txt",
                            { "Text Files (.txt .text)", "*.txt *.text" },
                            pfd::opt::force_overwrite);
    gLogi() << "Selected file: " << f.result();
}

void gipPortableFileDialogs::api() {
    // pfd::settings
    pfd::settings::verbose(true);
    pfd::settings::rescan();

    // pfd::notify
    pfd::notify("", "");
    pfd::notify("", "", pfd::icon::info);
    pfd::notify("", "", pfd::icon::warning);
    pfd::notify("", "", pfd::icon::error);
    pfd::notify("", "", pfd::icon::question);

    pfd::notify a("", "");
    (void)a.ready();
    (void)a.ready(42);

    // pfd::message
    pfd::message("", "");
    pfd::message("", "", pfd::choice::ok);
    pfd::message("", "", pfd::choice::ok_cancel);
    pfd::message("", "", pfd::choice::yes_no);
    pfd::message("", "", pfd::choice::yes_no_cancel);
    pfd::message("", "", pfd::choice::retry_cancel);
    pfd::message("", "", pfd::choice::abort_retry_ignore);
    pfd::message("", "", pfd::choice::ok, pfd::icon::info);
    pfd::message("", "", pfd::choice::ok, pfd::icon::warning);
    pfd::message("", "", pfd::choice::ok, pfd::icon::error);
    pfd::message("", "", pfd::choice::ok, pfd::icon::question);

    pfd::message b("", "");
    (void)b.ready();
    (void)b.ready(42);
    (void)b.result();
}

