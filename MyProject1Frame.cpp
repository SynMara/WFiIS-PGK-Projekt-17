﻿#include "MyProject1Frame.h"

MyProject1Frame::MyProject1Frame(wxWindow* parent) :Frame(parent)
{
	SetCursor(_kursor);
	_kursor = wxCursor(*wxSTANDARD_CURSOR);

	_image1 = wxImage();
	_image2 = wxImage();
	_image3 = wxImage();
	_image2s = wxImage();

	_cpy1 = wxImage();
	_cpy2 = wxImage();
	_cpy3 = wxImage();
	wxInitAllImageHandlers();

	_pow = 1;
	_poz = 100;
	wxString s1;
	s1 << 50 * pow(2, _pow) << '%';
	m_textCtrl1->SetValue(s1);

	wxString s2;
	s2 << _poz << '%';
	m_textCtrl2->SetValue(s2);

	m_scrolledWindow2->ShowScrollbars(wxSHOW_SB_NEVER, wxSHOW_SB_NEVER);
	m_scrolledWindow21->ShowScrollbars(wxSHOW_SB_NEVER, wxSHOW_SB_NEVER);

	m_scrolledWindow1->SetBackgroundColour(wxColor(192, 192, 192));
	m_scrolledWindow2->SetBackgroundColour(wxColor(192, 192, 192));
	m_scrolledWindow21->SetBackgroundColour(wxColor(192, 192, 192));
}

void MyProject1Frame::Repaint(wxScrolledWindow* sw, wxImage& img) {
	wxBitmap bitmap(img);
	wxClientDC dc(sw);
	sw->DoPrepareDC(dc);
	dc.DrawBitmap(bitmap, 0, 0, true);
}

void MyProject1Frame::load_button1OnButtonClick(wxCommandEvent& event)
{
	wxClientDC dc1(m_scrolledWindow1);
	dc1.Clear();
	wxClientDC dc3(m_scrolledWindow21);
	dc3.Clear();
	if (_image3.GetWidth() > 0)
	{
		_image3.Destroy();
		_cpy3.Destroy();
	}
	wxString s;
	s << "";
	m_textCtrl3->SetValue(s);
	m_textCtrl4->SetValue(s);

	wxFileDialog* dialog = new wxFileDialog(this, "Prosz\u0119 wybra\u0107 zdj\u0119cie", "", "", wxT("Obraz BMP (*.bmp)|*.bmp|Obraz JPG (*.jpg)|*.jpg|Obraz PNG (*.png)|*.png"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);

	if (dialog->ShowModal() == wxID_CANCEL)
		return;

	if (_poz != 100)
	{
		_poz = 100;

		m_slider4->SetValue(100);
		wxString s;
		s << _poz << '%';
		m_textCtrl2->SetValue(s);

	}
	if (_pow != 1)
	{
		_pow = 1;

		m_slider3->SetValue(1);
		wxString s;
		s << 50 * pow(2, _pow) << '%';
		m_textCtrl1->SetValue(s);

	}
	_image1.LoadFile(dialog->GetPath(), wxBITMAP_TYPE_ANY);

	_w = _image1.GetHeight(); _h = _image1.GetWidth();

	if ((_w != _image2s.GetWidth() || _h != _image2s.GetHeight()) && _image2s.GetWidth() > 0)
	{
		wxClientDC dc2(m_scrolledWindow2);
		dc2.Clear();
		_image2s = _image2.Scale(_h, _w);
		_cpy2 = _image2s.Copy();
		Repaint(m_scrolledWindow2, _cpy2);
	}
	_cpy1 = _image1.Copy();

	m_scrolledWindow1->SetScrollbars(1, 1, _image1.GetWidth(), _image1.GetHeight());
	m_scrolledWindow2->SetScrollbars(1, 1, _image1.GetWidth(), _image1.GetHeight());
	m_scrolledWindow21->SetScrollbars(1, 1, _image1.GetWidth(), _image1.GetHeight());

	Repaint(m_scrolledWindow1, _image1);
}

void MyProject1Frame::load_button2OnButtonClick(wxCommandEvent& event)
{
	wxClientDC dc(m_scrolledWindow2);
	dc.Clear();
	wxClientDC dc3(m_scrolledWindow21);
	dc3.Clear();
	if (_image3.GetWidth() > 0)
	{
		_image3.Destroy();
		_cpy3.Destroy();
	}
	wxString s;
	s << "";
	m_textCtrl3->SetValue(s);
	m_textCtrl4->SetValue(s);

	wxFileDialog* dialog = new wxFileDialog(this, "Prosz\u0119 wybra\u0107 zdj\u0119cie", "", "", wxT("Obraz BMP (*.bmp)|*.bmp|Obraz JPG (*.jpg)|*.jpg|Obraz PNG (*.png)|*.png"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);

	if (dialog->ShowModal() == wxID_CANCEL)
		return;

	_image2.LoadFile(dialog->GetPath(), wxBITMAP_TYPE_ANY);
	_image2s = _image2.Copy();

	if (_w != 0 && _h != 0)
		if (_cpy1.GetWidth() != _image2.GetWidth() || _cpy1.GetHeight() != _image2.GetHeight())
		{
			_image2s = _image2.Scale(_image1.GetWidth(), _image1.GetHeight());
		}

	_cpy2 = _image2.Scale(_cpy1.GetWidth(), _cpy1.GetHeight());

	Repaint(m_scrolledWindow2, _cpy2);
}

void MyProject1Frame::m_slider3OnScroll(wxScrollEvent& event)
{
	wxClientDC dc1(m_scrolledWindow1);
	wxClientDC dc2(m_scrolledWindow2);
	wxClientDC dc3(m_scrolledWindow21);
	if ((_image2.GetWidth() == 0 || _image2.GetHeight() == 0) || (_image1.GetWidth() == 0 || _image1.GetHeight() == 0))
	{
		m_slider3->SetValue(1);
		return;
	}
	if (_poz != 100)
	{
		_poz = 100;
		_cpy1 = _image1.Copy();
		_cpy2 = _image2s.Copy();
		_cpy3 = _image3.Copy();

		m_slider4->SetValue(100);
		wxString s;
		s << _poz << '%';
		m_textCtrl2->SetValue(s);
	}

	if (event.GetPosition() != _pow) {
		int tmp = event.GetPosition();
		_cpy1 = _image1.Scale((50 * pow(2, tmp) / 100) * _image1.GetWidth(), (50 * pow(2, tmp) / 100) * _image1.GetHeight());
		_cpy2 = _image2s.Scale((50 * pow(2, tmp) / 100) * _image2s.GetWidth(), (50 * pow(2, tmp) / 100) * _image2s.GetHeight());
		_cpy3 = _image3.Scale((50 * pow(2, tmp) / 100) * _image3.GetWidth(), (50 * pow(2, tmp) / 100) * _image3.GetHeight());

		_pow = tmp;
		wxString s;
		s << 50 * pow(2, _pow) << '%';
		m_textCtrl1->SetValue(s);
	}

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

void MyProject1Frame::m_button8OnButtonClick(wxCommandEvent& event)
{
	int licznik = 0;
	double podobienstwo = 0;
	if (_cpy1.GetHeight() == 0 || _cpy1.GetWidth() == 0 || _cpy2.GetHeight() == 0 || _cpy2.GetWidth() == 0) {
		wxMessageBox(wxT("Prosz\u0119 o wczytanie obu zdj\u0119\u0107!"), wxT("OSTRZE\u017BENIE"), wxOK | wxCENTRE);
		return;
	}

	wxClientDC dc(m_scrolledWindow21);
	dc.Clear();

	int w = _cpy1.GetWidth();
	int h = _cpy1.GetHeight();

	_image3 = _image1.Copy();
	_cpy3 = _cpy1.Copy();

	long int size = w * h * 3;

	unsigned char* imgData1 = _cpy1.GetData();
	unsigned char* imgData2 = _cpy2.GetData();
	unsigned char* imgData3 = _cpy3.GetData();

	for (long int i = 0; i < size; i++) {
		imgData3[i] = abs(imgData2[i] - imgData1[i]);
	}

	unsigned char* imgData1o = _image1.GetData();
	unsigned char* imgData2o = _image2s.GetData();
	unsigned char* imgData3o = _image3.GetData();

	w = _image1.GetWidth();
	h = _image1.GetHeight();
	size = w * h * 3;

	for (long int i = 0; i < size; i++) {
		imgData3o[i] = abs(imgData2o[i] - imgData1o[i]);
	}
	for (long int i = 0; i < size; i += 3) {
		if (imgData3o[i] == 0 && imgData3o[i + 1] == 0 && imgData3o[i + 2] == 0)
			licznik++;
	}

	wxString s1;
	s1 << round((double)licznik / (size / 3) * 100 * 100) / 100 << '%';
	m_textCtrl3->SetValue(s1);

	for (long int i = 0; i < size; i += 3) {
		podobienstwo += (double)(255 - imgData3o[i]) / 255 * (double)(255 - imgData3o[i + 1]) / 255 * (double)(255 - imgData3o[i + 2]) / 255;
	}
	wxString s2;
	s2 << round(podobienstwo / (size / 3) * 100 * 100) / 100 << '%';
	m_textCtrl4->SetValue(s2);

	Repaint(m_scrolledWindow21, _cpy3);
}

void MyProject1Frame::save_button5OnButtonClick(wxCommandEvent& event)
{
	if (_cpy3.GetHeight() == 0 || _cpy3.GetWidth() == 0) {
		wxMessageBox(wxT("Prosz\u0119 o zrobienie zdj\u0119cia r\u00F3\u017Cnicowego!"), wxT("OSTRZE\u017BENIE"), wxOK | wxCENTRE);
		return;
	}

	wxFileDialog* dialog = new wxFileDialog(this, "Prosz\u0119 wybra\u0107 lokalizacj\u0119", "", "", wxT("Obraz BMP (*.bmp)|*.bmp"), wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

	if (dialog->ShowModal() == wxID_CANCEL)
		return;

	_image3.SaveFile(dialog->GetPath());
}

void MyProject1Frame::m_scrolledWindow1OnUpdateUI(wxUpdateUIEvent& event)
{
	Repaint(m_scrolledWindow1, _cpy1);

	m_scrolledWindow2->Scroll(m_scrolledWindow1->GetScrollPos(wxHORIZONTAL), m_scrolledWindow1->GetScrollPos(wxVERTICAL));
	m_scrolledWindow21->Scroll(m_scrolledWindow1->GetScrollPos(wxHORIZONTAL), m_scrolledWindow1->GetScrollPos(wxVERTICAL));

	event.Skip();
}

void MyProject1Frame::m_scrolledWindow2OnUpdateUI(wxUpdateUIEvent& event)
{
	Repaint(m_scrolledWindow2, _cpy2);

	event.Skip();
}

void MyProject1Frame::m_scrolledWindow21OnUpdateUI(wxUpdateUIEvent& event)
{
	Repaint(m_scrolledWindow21, _cpy3);

	event.Skip();
}

void MyProject1Frame::m_slider4OnScroll(wxScrollEvent& event)
{
	wxClientDC dc1(m_scrolledWindow1);
	wxClientDC dc2(m_scrolledWindow2);
	wxClientDC dc3(m_scrolledWindow21);

	if ((_image2.GetWidth() == 0 || _image2.GetHeight() == 0) || (_image1.GetWidth() == 0 || _image1.GetHeight() == 0))
	{
		m_slider4->SetValue(100);
		return;
	}

	if (_pow != 1)
	{
		_pow = 1;
		_cpy1 = _image1.Copy();
		_cpy2 = _image2s.Copy();
		_cpy3 = _image3.Copy();

		m_slider3->SetValue(1);
		wxString s;
		s << 50 * pow(2, _pow) << '%';
		m_textCtrl1->SetValue(s);
	}

	double z = 0;
	if (event.GetPosition() != _poz) {

		z = event.GetPosition();
		_cpy1 = _image1.Scale((z / 100.0) * _h, (z / 100.0) * _w);
		_cpy2 = _image2s.Scale((z / 100.0) * _h, (z / 100.0) * _w);
		_cpy3 = _image3.Scale((z / 100.0) * _h, (z / 100.0) * _w);
		_poz = event.GetPosition();
		wxString s;
		s << _poz << '%';
		m_textCtrl2->SetValue(s);
	}

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

void MyProject1Frame::m_scrolledWindow1OnMouseEvents(wxMouseEvent& event)
{
	if (event.LeftDown() && ((int)event.GetX() <= _cpy1.GetWidth() && (int)event.GetY() <= _cpy1.GetHeight()) && _klik)
	{
		px1 = (int)event.GetX();
		py1 = (int)event.GetY();
		wxClientDC dc1(m_scrolledWindow1);
		dc1.SetBrush(*wxTRANSPARENT_BRUSH);
		dc1.DrawRectangle(px1, py1, (int)event.GetX() - px1, (int)event.GetY() - py1);
	}
	if (event.LeftIsDown() && ((int)event.GetX() <= _cpy1.GetWidth() && (int)event.GetY() <= _cpy1.GetHeight()) && _klik)
	{
		wxClientDC dc1(m_scrolledWindow1);
		dc1.SetBrush(*wxTRANSPARENT_BRUSH);
		dc1.DrawRectangle(px1, py1, (int)event.GetX() - px1, (int)event.GetY() - py1);
	}
	if (event.LeftUp() && ((int)event.GetX() <= _cpy1.GetWidth() && (int)event.GetY() <= _cpy1.GetHeight()) && _klik)
	{
		px2 = (int)event.GetX();
		py2 = (int)event.GetY();
		if (px1 > px2)
			std::swap(px1, px2);
		if (py1 > py2)
			std::swap(py1, py2);

		wxClientDC dc1(m_scrolledWindow1);
		dc1.SetBrush(*wxTRANSPARENT_BRUSH);
		dc1.DrawRectangle(px1, py1, px2 - px1, py2 - py1);

		wxRect* rect1 = new wxRect(px1, py1, px2 - px1, py2 - py1);
		wxImage img1, img2, img;
		int w = 2 * (px2 - px1);
		int h = py2 - py1;

		img1 = _cpy1.GetSubImage(*rect1);
		img2 = _cpy2.GetSubImage(*rect1);

		img = wxImage(w, h);
		long int size = w * h * 3;

		unsigned char* imgData1 = img1.GetData();
		unsigned char* imgData2 = img2.GetData();
		unsigned char* imgData3 = img.GetData();
		long int j = 0, k = 0, size2 = size / 2;
		for (long int i = 0; i < size; i++) {

			if ((i / (3 * (w / 2))) % 2 == 0) {
				imgData3[i] = imgData1[j];
				j++;
			}
			else {
				imgData3[i] = imgData2[k];
				k++;
			}
		}

		wxFileDialog* dialog = new wxFileDialog(this, "Prosz\u0119 wybra\u0107 lokalizacj\u0119", "", "", wxT("Obraz BMP (*.bmp)|*.bmp"), wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

		if (dialog->ShowModal() == wxID_CANCEL)
			return;

		img.SaveFile(dialog->GetPath());

		delete rect1;
		_klik = false;
		_kursor = wxCursor(*wxSTANDARD_CURSOR);
		SetCursor(_kursor);
	}
}

void MyProject1Frame::save_button6OnButtonClick(wxCommandEvent& event)
{
	if ((_image2.GetWidth() != 0 && _image2.GetHeight() != 0) && (_image1.GetWidth() != 0 && _image1.GetHeight() != 0))
	{
		if (!_klik)
		{
			_klik = true;
			_kursor = wxCursor(*wxCROSS_CURSOR);
			SetCursor(_kursor);
		}
		else
		{
			_klik = false;
			_kursor = wxCursor(*wxSTANDARD_CURSOR);
			SetCursor(_kursor);
		}
	}
	else {
		wxMessageBox(wxT("Prosz\u0119 o wczytanie obu zdj\u0119\u0107!"), wxT("OSTRZE\u017BENIE"), wxOK | wxCENTRE);
		return;
	}
}