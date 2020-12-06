#pragma once

#include "wx/wx.h"
#include <wx/listctrl.h>
#include <wx/wfstream.h>
#include <wx/txtstrm.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>

class Main : public wxFrame
{

public:
	Main();
	~Main(); 

public:
	wxButton* add_button = nullptr;
	wxTextCtrl* input = nullptr;
	wxListBox* data_list = nullptr;
	wxMenuBar* menu_bar = nullptr;
	wxMenu* menu = nullptr;
	wxMenuItem* config_item = nullptr;

	void OnButtonPress(wxCommandEvent& evt);
	void OnRightPressOnList(wxMouseEvent& evt);
	void OnMenuPress(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();

private:
	void PopulateList();
};

