///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gdicmn.h>
#include <wx/button.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/slider.h>
#include <wx/sizer.h>
#include <wx/scrolwin.h>
#include <wx/frame.h>
#include <wx/textctrl.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class Frame
///////////////////////////////////////////////////////////////////////////////
class Frame : public wxFrame
{
	private:

	protected:
		wxButton* load_button1;
		wxButton* load_button2;
		wxSlider* m_slider3;
		wxButton* m_button8;
		wxButton* save_button5;
		wxScrolledWindow* m_scrolledWindow1;
		wxScrolledWindow* m_scrolledWindow2;
		wxScrolledWindow* m_scrolledWindow21;

		wxSlider* m_slider4;
		wxTextCtrl* m_textCtrl1;
		wxTextCtrl* m_textCtrl2;


		// Virtual event handlers, overide them in your derived class
		virtual void load_button1OnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void load_button2OnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_slider3OnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_button8OnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void save_button5OnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_scrolledWindow1OnUpdateUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void m_scrolledWindow2OnUpdateUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void m_scrolledWindow21OnUpdateUI( wxUpdateUIEvent& event ) { event.Skip(); }

		virtual void m_slider4OnScroll(wxScrollEvent& event) { event.Skip(); }
		virtual void m_textCtrl1OnText(wxCommandEvent& event) { event.Skip(); }
		virtual void m_textCtrl2OnText(wxCommandEvent& event) { event.Skip(); }


	public:

		Frame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("GFK projekt 17"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1200,400 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~Frame();

};

