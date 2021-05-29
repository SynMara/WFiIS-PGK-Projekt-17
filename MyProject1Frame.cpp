#include "MyProject1Frame.h"
#include <string>
#include <wx/rawbmp.h>
#include <wx/colour.h>

//1. poprawic proporcje w powiekszaniu/pomniejszaniu(50%, 100%, 200%, 400%)															+++
//2. powiekszanie/pomniejszanie tylko kopia żeby zapisywać w oryginalnym wymiarze(albo przechowywać oryginalne wymiary)				+++
//3. wczytywanie 2 zdjęcia po tym jak powiększyliśmy pierwsze (niech się wczytuje powiększone w ten sam sposób)						
//4. przygotwac kilka jakichs ciekawych bitmap, i to zdjęcie z szumem, zeby zaprezentowac działanie i dokumentacja					
//5. opisac powiekszanie																											
//6. komunikat jak wczytalismy inne rozmiary (przy robieniu zdjecia roznicowego)													zbedne
//7. slidery - ruszanie tylko jednym, jesli pierwszy przestawiony, a ruch w drugim, to pierwszy na pozycje poczatkowa																									


MyProject1Frame::MyProject1Frame( wxWindow* parent ):Frame( parent )
{
	_image1 = wxImage();
	_image2 = wxImage();
	_image3 = wxImage();

	_cpy1 = wxImage();
	_cpy2 = wxImage();
	_cpy3 = wxImage();
	
	_pow = 1;

	m_scrolledWindow2->ShowScrollbars(wxSHOW_SB_NEVER, wxSHOW_SB_NEVER);
	m_scrolledWindow21->ShowScrollbars(wxSHOW_SB_NEVER, wxSHOW_SB_NEVER);

	m_scrolledWindow1->SetBackgroundColour(wxColor(192, 192, 192));
	m_scrolledWindow2->SetBackgroundColour(wxColor(192, 192, 192));
	m_scrolledWindow21->SetBackgroundColour(wxColor(192, 192, 192));
}

void MyProject1Frame::Repaint(wxScrolledWindow* sw, wxImage &img) {
	wxBitmap bitmap(img);
	wxClientDC dc(sw);
	sw->DoPrepareDC(dc);
	dc.DrawBitmap(bitmap, 0, 0, true);
}

void MyProject1Frame::load_button1OnButtonClick( wxCommandEvent& event )
{
	wxClientDC dc1(m_scrolledWindow1);
	dc1.Clear();

	wxFileDialog * dialog = new wxFileDialog(this, "Prosze wybrac zdjecie", "", "", wxT("Obraz BMP (*.bmp)|*.bmp"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);
	
	if (dialog->ShowModal() == wxID_CANCEL)
		return;

	_image1.LoadFile(dialog->GetPath(), wxBITMAP_TYPE_ANY);

	
	_w = _image1.GetHeight(); _h = _image1.GetWidth();

	if ((_w != _image2.GetWidth() || _h != _image2.GetHeight() ) && _image2.GetWidth()>0)
	{
		wxClientDC dc2(m_scrolledWindow2);
		dc2.Clear();
		_image2.Rescale(_h, _w, wxIMAGE_QUALITY_HIGH);
		_cpy2=_image2.Copy();
		Repaint(m_scrolledWindow2, _cpy2);
	}

	
	_cpy1=_image1.Copy();
	
	m_scrolledWindow1->SetScrollbars(1, 1, _image1.GetWidth(), _image1.GetHeight());
	m_scrolledWindow2->SetScrollbars(1, 1, _image1.GetWidth(), _image1.GetHeight());
	m_scrolledWindow21->SetScrollbars(1, 1, _image1.GetWidth(), _image1.GetHeight());

	Repaint(m_scrolledWindow1, _image1);
}

void MyProject1Frame::load_button2OnButtonClick( wxCommandEvent& event )
{
	wxClientDC dc(m_scrolledWindow2);
	dc.Clear();
	//if (_w != 0 && _h != 0){
		wxFileDialog* dialog = new wxFileDialog(this, "Prosze wybrac zdjecie", "", "", wxT("Obraz BMP (*.bmp)|*.bmp"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);

		if (dialog->ShowModal() == wxID_CANCEL)
			return;

		_image2.LoadFile(dialog->GetPath(), wxBITMAP_TYPE_ANY);

		if (_w != 0 && _h != 0)
			if (_w != _image2.GetWidth() || _h != _image2.GetHeight())
			{
				_image2.Rescale(_h, _w, wxIMAGE_QUALITY_HIGH);
			}

		_cpy2 = _image2.Copy();

		Repaint(m_scrolledWindow2, _image2);
	//}
}

void MyProject1Frame::m_slider3OnScroll( wxScrollEvent& event )
{
	wxClientDC dc1(m_scrolledWindow1);
	wxClientDC dc2(m_scrolledWindow2);
	wxClientDC dc3(m_scrolledWindow21);

	if (event.GetPosition() >= _pow) {
		_cpy1.Rescale(2*_cpy1.GetWidth(), 2*_cpy1.GetHeight());
		_cpy2.Rescale(2*_cpy2.GetWidth(), 2*_cpy2.GetHeight());
		_cpy3.Rescale(2*_cpy3.GetWidth(), 2*_cpy3.GetHeight());

		_pow += 1;
	}
	else {
		_cpy1.Rescale(0.5*_cpy1.GetWidth(), 0.5*_cpy1.GetHeight());
		_cpy2.Rescale(0.5*_cpy2.GetWidth(), 0.5*_cpy2.GetHeight());
		_cpy3.Rescale(0.5*_cpy3.GetWidth(), 0.5*_cpy3.GetHeight());

		_pow -= 1;
	}

	/*_image1 = _cpy1.Copy();
	_image2 = _cpy2.Copy();
	_image3 = _cpy3.Copy();*/

	m_scrolledWindow1->SetScrollbars(1, 1, _cpy1.GetWidth(), _cpy1.GetHeight());
	m_scrolledWindow2->SetScrollbars(1, 1, _cpy1.GetWidth(), _cpy1.GetHeight());
	m_scrolledWindow21->SetScrollbars(1, 1, _cpy1.GetWidth(), _cpy1.GetHeight());

	dc1.Clear();
	dc2.Clear();
	dc3.Clear();

	Repaint(m_scrolledWindow1, _cpy1);
	Repaint(m_scrolledWindow2, _cpy2);
	Repaint(m_scrolledWindow21, _cpy3);
// TODO: Implement m_slider3OnScroll - to do poprawy
}

void MyProject1Frame::m_button8OnButtonClick(wxCommandEvent& event)
{
	if (_cpy1.GetHeight() != _cpy2.GetHeight() || _cpy1.GetWidth() != _cpy2.GetWidth()) {
		return;
	}
	
	wxClientDC dc(m_scrolledWindow21);
	dc.Clear();

	int w = _cpy1.GetWidth();
	int h = _cpy1.GetHeight();

	_image3=_image1.Copy();
	_cpy3 = _image3.Copy();

	int size = w * h * 3;

	unsigned char* imgData1 = _cpy1.GetData();
	unsigned char* imgData2 = _cpy2.GetData();
	unsigned char* imgData3 = _cpy3.GetData();

	for (int i = 0; i < size; i++) {
		imgData3[i] = abs(imgData2[i] - imgData1[i]);
	}

	_image3 = _cpy3.Copy();
	Repaint(m_scrolledWindow21, _cpy3);
}

void MyProject1Frame::save_button5OnButtonClick( wxCommandEvent& event )
{
	wxFileDialog * dialog = new wxFileDialog(this, "Prosze wybrac lokalizacje", "", "", wxT("Obraz BMP (*.bmp)|*.bmp"), wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

	if (dialog->ShowModal() == wxID_CANCEL)
		return;
	
	_image3.SaveFile(dialog->GetPath());
}

void MyProject1Frame::m_scrolledWindow1OnUpdateUI( wxUpdateUIEvent& event )
{
	Repaint(m_scrolledWindow1, _cpy1);

	m_scrolledWindow2->Scroll(m_scrolledWindow1->GetScrollPos(wxHORIZONTAL), m_scrolledWindow1->GetScrollPos(wxVERTICAL));
	m_scrolledWindow21->Scroll(m_scrolledWindow1->GetScrollPos(wxHORIZONTAL), m_scrolledWindow1->GetScrollPos(wxVERTICAL));

	event.Skip();
}

void MyProject1Frame::m_scrolledWindow2OnUpdateUI( wxUpdateUIEvent& event )
{
	Repaint(m_scrolledWindow2, _cpy2);

	event.Skip();
}

void MyProject1Frame::m_scrolledWindow21OnUpdateUI( wxUpdateUIEvent& event )
{
	Repaint(m_scrolledWindow21, _cpy3);

	event.Skip();
}

void MyProject1Frame::m_slider4OnScroll(wxScrollEvent& event)
{
	wxClientDC dc1(m_scrolledWindow1);
	wxClientDC dc2(m_scrolledWindow2);
	wxClientDC dc3(m_scrolledWindow21);
	double z = 0;
	if (event.GetPosition() != poz) {
		
		z = 1+event.GetPosition();
		_cpy1=_image1.Scale((z / 100.0) * _h, (z / 100.0) * _w, wxIMAGE_QUALITY_HIGH);
		_cpy2=_image2.Scale((z / 100.0) * _h, (z / 100.0) * _w, wxIMAGE_QUALITY_HIGH);
		_cpy3=_image3.Scale((z / 100.0) * _h, (z / 100.0) * _w, wxIMAGE_QUALITY_HIGH);
		poz = event.GetPosition();
	}
	

	/*_image1 = _cpy1.Copy();
	_image2 = _cpy2.Copy();
	_image3 = _cpy3.Copy();*/

	m_scrolledWindow1->SetScrollbars(1, 1, _cpy1.GetWidth(), _cpy1.GetHeight());
	m_scrolledWindow2->SetScrollbars(1, 1, _cpy1.GetWidth(), _cpy1.GetHeight());
	m_scrolledWindow21->SetScrollbars(1, 1, _cpy1.GetWidth(), _cpy1.GetHeight());

	dc1.Clear();
	dc2.Clear();
	dc3.Clear();

	Repaint(m_scrolledWindow1, _cpy1);
	Repaint(m_scrolledWindow2, _cpy2);
	Repaint(m_scrolledWindow21, _cpy3);
}
