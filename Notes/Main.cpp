#include "Main.h"

wxBEGIN_EVENT_TABLE(Main, wxFrame)
	EVT_BUTTON(201, OnButtonPress)
wxEND_EVENT_TABLE()

Main::Main() : wxFrame(nullptr, wxID_ANY, "Notes", wxPoint(0, 0), wxSize(800, 600))
{
	input = new wxTextCtrl(this, wxID_ANY, "", wxPoint(24, 40), wxSize(240, 20));
	add_button = new wxButton(this, 201, "Add", wxPoint(24, 64), wxSize(40, 16));
	data_list = new wxListBox(this, wxID_ANY, wxPoint(24, 120), wxSize(280, 280), 0, NULL, wxLB_MULTIPLE);

	data_list->Connect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(Main::OnRightPressOnList), NULL, this);
}

Main::~Main()
{

}

void Main::OnButtonPress(wxCommandEvent& event)
{
	data_list->AppendString(input->GetValue());
	event.Skip();
}

/*
	Opens a context menu, with the following options:
		- DELETE
*/
void Main::OnRightPressOnList(wxMouseEvent& event)
{
	wxMenu mnu;
	mnu.Append(101, "Delete");
	mnu.Connect(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Main::OnMenuPress), NULL, this);
	PopupMenu(&mnu);
	event.Skip();
}

/*
	Executes action from context menu press
		- DELETE selection
*/
void Main::OnMenuPress(wxCommandEvent& event) 
{
	wxArrayInt selections;
	data_list->GetSelections(selections);
	for (int i = selections.GetCount() - 1; i >= 0; i--)
	{
		data_list->Delete(i);
	}
	event.Skip();
}