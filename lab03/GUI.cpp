///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MyFrame1::MyFrame1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	m_panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	bSizer2->Add( m_panel, 1, wxEXPAND | wxALL, 5 );


	bSizer1->Add( bSizer2, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	m_button_write = new wxButton( this, wxID_ANY, wxT("Zapis do pliku"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_button_write, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_checkBox_banan = new wxCheckBox( this, wxID_ANY, wxT("banan"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_checkBox_banan, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_scrollBar = new wxScrollBar( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSB_HORIZONTAL );
	m_scrollBar->SetScrollbar(0, 1, 100, 1);
	m_scrollBar->Disable();
	bSizer3->Add( m_scrollBar, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );

	m_gauge = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	m_gauge->SetValue( 0 );
	bSizer3->Add( m_gauge, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_button_color = new wxButton( this, wxID_ANY, wxT("Kolor gwiazdki"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_button_color, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_textCtrl = new wxTextCtrl( this, wxID_ANY, wxT("tekst"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_textCtrl, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxString m_choiceChoices[] = { wxT("gwiazdka"), wxT("ksiezyc"), wxT("slonko") };
	int m_choiceNChoices = sizeof( m_choiceChoices ) / sizeof( wxString );
	m_choice = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceNChoices, m_choiceChoices, 0 );
	m_choice->SetSelection( 0 );
	bSizer3->Add( m_choice, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer1->Add( bSizer3, 0, 0, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );
	MyImage.AddHandler(new wxPNGHandler);

	wxColourDialog colorDlg(this);
	// Connect Events
	m_panel->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::m_panelOnUpdateUI ), NULL, this );
	m_button_write->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button_writeOnButtonClick ), NULL, this );
	m_checkBox_banan->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame1::m_checkBox_bananOnCheckBox ), NULL, this );
	m_button_color->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button_colorOnButtonClick ), NULL, this );
	m_textCtrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::m_textCtrlOnText ), NULL, this );
	m_choice->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyFrame1::m_choiceOnChoice ), NULL, this );
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	m_panel->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::m_panelOnUpdateUI ), NULL, this );
	m_button_write->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button_writeOnButtonClick ), NULL, this );
	m_checkBox_banan->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame1::m_checkBox_bananOnCheckBox ), NULL, this );
	m_button_color->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button_colorOnButtonClick ), NULL, this );
	m_textCtrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::m_textCtrlOnText ), NULL, this );
	m_choice->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyFrame1::m_choiceOnChoice ), NULL, this );

}
