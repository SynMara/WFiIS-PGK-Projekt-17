///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MyFrame.h"

///////////////////////////////////////////////////////////////////////////

Frame::Frame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* sizer2;
	sizer2 = new wxBoxSizer( wxVERTICAL );

	load_button1 = new wxButton( this, wxID_ANY, wxT("Wczytaj zdj. 1"), wxDefaultPosition, wxDefaultSize, 0 );
	sizer2->Add( load_button1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	load_button2 = new wxButton( this, wxID_ANY, wxT("Wczytaj zdj. 2"), wxDefaultPosition, wxDefaultSize, 0 );
	sizer2->Add( load_button2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_textCtrl1 = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(50, 27), wxTE_READONLY);
	sizer2->Add(m_textCtrl1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);

	m_slider3 = new wxSlider( this, wxID_ANY, 1, 0, 3, wxDefaultPosition, wxDefaultSize );
	sizer2->Add( m_slider3, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5 );

	m_button8 = new wxButton( this, wxID_ANY, wxT("Zdj. r\u00F3\u017Cnicowe"), wxDefaultPosition, wxDefaultSize, 0 );
	sizer2->Add( m_button8, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5 );

	save_button5 = new wxButton( this, wxID_ANY, wxT("Zapisz do BMP"), wxDefaultPosition, wxDefaultSize, 0 );
	sizer2->Add( save_button5, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5 );

	m_textCtrl2 = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(50, 27), wxTE_READONLY);
	sizer2->Add(m_textCtrl2, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	m_slider4 = new wxSlider(this, wxID_ANY, 100, 1, 400, wxDefaultPosition, wxDefaultSize );
	sizer2->Add(m_slider4, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	m_staticText1 = new wxStaticText(this, wxID_ANY, wxT("Por\u00F3wnywanie pikseli"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText1->Wrap(-1);
	sizer2->Add(m_staticText1, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);
	
	m_textCtrl3 = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(62, 27), wxTE_READONLY);
	sizer2->Add(m_textCtrl3, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	m_staticText2 = new wxStaticText(this, wxID_ANY, wxT("Por\u00F3wnywanie kolor\u00F3w"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText2->Wrap(-1);
	sizer2->Add(m_staticText2, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	m_textCtrl4 = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(62, 27), wxTE_READONLY);
	sizer2->Add(m_textCtrl4, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	save_button6 = new wxButton(this, wxID_ANY, wxT("Wytnij i zapisz"), wxDefaultPosition, wxDefaultSize, 0);
	sizer2->Add(save_button6, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);



	bSizer2->Add( sizer2, 0, wxEXPAND, 5 );

	m_scrolledWindow1 = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow1->SetScrollRate( 5, 5 );
	m_scrolledWindow1->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BACKGROUND ) );

	bSizer2->Add( m_scrolledWindow1, 1, wxEXPAND | wxALL, 5 );

	m_scrolledWindow2 = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow2->SetScrollRate( 5, 5 );
	m_scrolledWindow2->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BACKGROUND ) );

	bSizer2->Add( m_scrolledWindow2, 1, wxEXPAND | wxALL, 5 );

	m_scrolledWindow21 = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow21->SetScrollRate( 5, 5 );
	m_scrolledWindow21->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BACKGROUND ) );

	bSizer2->Add( m_scrolledWindow21, 1, wxEXPAND | wxALL, 5 );


	this->SetSizer( bSizer2 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	load_button1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Frame::load_button1OnButtonClick ), NULL, this );
	load_button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Frame::load_button2OnButtonClick ), NULL, this );
	m_slider3->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Frame::m_slider3OnScroll ), NULL, this );
	m_slider3->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Frame::m_slider3OnScroll ), NULL, this );
	m_slider3->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Frame::m_slider3OnScroll ), NULL, this );
	m_slider3->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Frame::m_slider3OnScroll ), NULL, this );
	m_slider3->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Frame::m_slider3OnScroll ), NULL, this );
	m_slider3->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Frame::m_slider3OnScroll ), NULL, this );
	m_slider3->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Frame::m_slider3OnScroll ), NULL, this );
	m_slider3->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Frame::m_slider3OnScroll ), NULL, this );
	m_slider3->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Frame::m_slider3OnScroll ), NULL, this );
	m_button8->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Frame::m_button8OnButtonClick ), NULL, this );
	save_button5->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Frame::save_button5OnButtonClick ), NULL, this );
	m_scrolledWindow1->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( Frame::m_scrolledWindow1OnUpdateUI ), NULL, this );
	m_scrolledWindow2->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( Frame::m_scrolledWindow2OnUpdateUI ), NULL, this );
	m_scrolledWindow21->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( Frame::m_scrolledWindow21OnUpdateUI ), NULL, this );
	m_slider4->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(Frame::m_slider4OnScroll), NULL, this);
	m_slider4->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(Frame::m_slider4OnScroll), NULL, this);
	m_slider4->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(Frame::m_slider4OnScroll), NULL, this);
	m_slider4->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(Frame::m_slider4OnScroll), NULL, this);
	m_slider4->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(Frame::m_slider4OnScroll), NULL, this);
	m_slider4->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(Frame::m_slider4OnScroll), NULL, this);
	m_slider4->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(Frame::m_slider4OnScroll), NULL, this);
	m_slider4->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(Frame::m_slider4OnScroll), NULL, this);
	m_slider4->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(Frame::m_slider4OnScroll), NULL, this);
	m_textCtrl1->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(Frame::m_textCtrl1OnText), NULL, this);
	m_textCtrl2->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(Frame::m_textCtrl1OnText), NULL, this);
	m_textCtrl3->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(Frame::m_textCtrl1OnText), NULL, this);
	m_textCtrl4->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(Frame::m_textCtrl1OnText), NULL, this);
	m_scrolledWindow1->Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(Frame::m_scrolledWindow1OnMouseEvents), NULL, this);
	m_scrolledWindow1->Connect(wxEVT_LEFT_UP, wxMouseEventHandler(Frame::m_scrolledWindow1OnMouseEvents), NULL, this);
	m_scrolledWindow1->Connect(wxEVT_MOTION, wxMouseEventHandler(Frame::m_scrolledWindow1OnMouseEvents), NULL, this);
	save_button6->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Frame::save_button6OnButtonClick), NULL, this);
}

Frame::~Frame()
{
	// Disconnect Events
	load_button1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Frame::load_button1OnButtonClick ), NULL, this );
	load_button2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Frame::load_button2OnButtonClick ), NULL, this );
	m_slider3->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Frame::m_slider3OnScroll ), NULL, this );
	m_slider3->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Frame::m_slider3OnScroll ), NULL, this );
	m_slider3->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Frame::m_slider3OnScroll ), NULL, this );
	m_slider3->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Frame::m_slider3OnScroll ), NULL, this );
	m_slider3->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Frame::m_slider3OnScroll ), NULL, this );
	m_slider3->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Frame::m_slider3OnScroll ), NULL, this );
	m_slider3->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Frame::m_slider3OnScroll ), NULL, this );
	m_slider3->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Frame::m_slider3OnScroll ), NULL, this );
	m_slider3->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Frame::m_slider3OnScroll ), NULL, this );
	m_button8->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Frame::m_button8OnButtonClick ), NULL, this );
	save_button5->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Frame::save_button5OnButtonClick ), NULL, this );
	m_scrolledWindow1->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( Frame::m_scrolledWindow1OnUpdateUI ), NULL, this );
	m_scrolledWindow2->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( Frame::m_scrolledWindow2OnUpdateUI ), NULL, this );
	m_scrolledWindow21->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( Frame::m_scrolledWindow21OnUpdateUI ), NULL, this );
	m_slider4->Disconnect(wxEVT_SCROLL_TOP, wxScrollEventHandler(Frame::m_slider4OnScroll), NULL, this);
	m_slider4->Disconnect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(Frame::m_slider4OnScroll), NULL, this);
	m_slider4->Disconnect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(Frame::m_slider4OnScroll), NULL, this);
	m_slider4->Disconnect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(Frame::m_slider4OnScroll), NULL, this);
	m_slider4->Disconnect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(Frame::m_slider4OnScroll), NULL, this);
	m_slider4->Disconnect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(Frame::m_slider4OnScroll), NULL, this);
	m_slider4->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(Frame::m_slider4OnScroll), NULL, this);
	m_slider4->Disconnect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(Frame::m_slider4OnScroll), NULL, this);
	m_slider4->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(Frame::m_slider4OnScroll), NULL, this);
	m_textCtrl1->Disconnect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(Frame::m_textCtrl1OnText), NULL, this);
	m_textCtrl2->Disconnect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(Frame::m_textCtrl1OnText), NULL, this);
	m_textCtrl3->Disconnect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(Frame::m_textCtrl1OnText), NULL, this);
	m_textCtrl4->Disconnect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(Frame::m_textCtrl1OnText), NULL, this);
	m_scrolledWindow1->Disconnect(wxEVT_LEFT_DOWN, wxMouseEventHandler(Frame::m_scrolledWindow1OnMouseEvents), NULL, this);
	m_scrolledWindow1->Disconnect(wxEVT_LEFT_UP, wxMouseEventHandler(Frame::m_scrolledWindow1OnMouseEvents), NULL, this);
	m_scrolledWindow1->Disconnect(wxEVT_MOTION, wxMouseEventHandler(Frame::m_scrolledWindow1OnMouseEvents), NULL, this);
	save_button6->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Frame::save_button6OnButtonClick), NULL, this);
}
