#pragma once

#include "wx/wx.h"
#include <wx/listctrl.h>

class Main : public wxFrame
{

public:
	Main();
	~Main(); 

public:
	wxButton* add_button = nullptr;
	wxTextCtrl* input = nullptr;
	wxListBox* data_list = nullptr;

	void OnButtonPress(wxCommandEvent& evt);
	void OnRightPressOnList(wxMouseEvent& evt);
	void OnMenuPress(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};

