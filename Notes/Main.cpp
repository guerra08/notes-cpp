#include "Main.h"

wxBEGIN_EVENT_TABLE(Main, wxFrame)
	EVT_BUTTON(201, OnButtonPress)
wxEND_EVENT_TABLE()

Main::Main() : wxFrame(nullptr, wxID_ANY, "Notes", wxPoint(0, 0), wxSize(800, 600))
{
	menu_bar = new wxMenuBar();
	menu = new wxMenu();
	config_item = new wxMenuItem(menu, wxID_ANY, _("Storage file"), _("Toggle the management area"), wxITEM_NORMAL);

	menu->Append(config_item);
	menu_bar->Append(menu, _T("&File"));

	SetMenuBar(menu_bar);

	input = new wxTextCtrl(this, wxID_ANY, "", wxPoint(24, 40), wxSize(240, 20));
	add_button = new wxButton(this, 201, "Add", wxPoint(24, 64), wxSize(40, 16));
	data_list = new wxListBox(this, wxID_ANY, wxPoint(24, 120), wxSize(280, 280), 0, NULL, wxLB_MULTIPLE);

	PopulateList();

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

/*
	Populates the list with the notes on %userprofile%\documents
*/
void Main::PopulateList() {
	wxString docs_path = wxStandardPaths::Get().GetDocumentsDir();
	wxFileName fname = wxFileName(docs_path, "notes-store.txt");
	if (fname.FileExists()) {
		wxFileInputStream input(fname.GetFullPath());
		wxTextInputStream text(input);
		while (input.IsOk() && !input.Eof())
		{
			wxString line = text.ReadLine();
			data_list->AppendString(line);
		}
	}
}