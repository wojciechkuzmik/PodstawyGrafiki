#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
MyFrame1( parent )
{

}

void GUIMyFrame1::m_panelOnUpdateUI( wxUpdateUIEvent& event )
{
	Repaint();
}

void GUIMyFrame1::m_button_writeOnButtonClick( wxCommandEvent& event )
{
// TODO: Implement m_button_writeOnButtonClick
}

void GUIMyFrame1::m_checkBox_bananOnCheckBox( wxCommandEvent& event )
{
	if (m_checkBox_banan->IsChecked()) {
		m_scrollBar->Enable();
		MyImage.LoadFile("banan.png", wxBITMAP_TYPE_PNG);
		MyBitmap = wxBitmap(MyImage);
		Repaint();
	}
	else {
		m_scrollBar->Disable();
		Repaint();
	}
}

void GUIMyFrame1::m_scrollBarOnScroll(wxScrollEvent& event)
{
	Repaint();
}

void GUIMyFrame1::m_button_colorOnButtonClick( wxCommandEvent& event )
{
	colorDlg.ShowModal();
	Repaint();
}

void GUIMyFrame1::m_textCtrlOnText( wxCommandEvent& event )
{
	Repaint();
}

void GUIMyFrame1::m_choiceOnChoice( wxCommandEvent& event )
{
	Repaint();
}

void GUIMyFrame1::Repaint() {
	wxClientDC dc(m_panel);
	dc.SetBackground(wxColor(255, 255, 255));
	dc.Clear();
	wxCoord w, h;
	dc.GetSize(&w, &h);
	wxPoint smile[3];
	
	if (m_checkBox_banan->IsChecked()) {
		dc.DrawBitmap(MyBitmap, w / 2 - 70, h / 2 + 40 - m_scrollBar->GetThumbPosition());
		smile[0] = wxPoint(w / 2 - 10, h / 2 - 40);
		smile[1] = wxPoint(w / 2, h / 2 - 35);
		smile[2] = wxPoint(w / 2 + 10, h / 2 - 40);
	}
	else {
		smile[0] = wxPoint(w / 2 - 10, h / 2 - 40);
		smile[1] = wxPoint(w / 2, h / 2 - 45);
		smile[2] = wxPoint(w / 2 + 10, h / 2 - 40);
	}
	
	dc.DrawCircle(w / 2, h / 2 - 50, 30);
	dc.DrawCircle(w / 2 - 8, h / 2 - 62, 4);
	dc.DrawCircle(w / 2 + 8, h / 2 - 62, 4);
	dc.DrawSpline(3, smile);
	dc.DrawLine(w / 2, h / 2 - 20, w / 2, h / 2 + 100);
	dc.DrawLine(w / 2, h / 2 + 100, w / 2 - 40, h / 2 + 160);
	dc.DrawLine(w / 2, h / 2 + 100, w / 2 + 40, h / 2 + 160);
	dc.DrawLine(w / 2, h / 2 + 10, w / 2 + 50, h / 2 + 60);
	dc.DrawLine(w / 2, h / 2 + 10, w / 2 - 50, h / 2 + 60 - m_scrollBar->GetThumbPosition());
	dc.DrawText(m_textCtrl->GetValue(), w / 2 - 100, h / 2 + 180);
	dc.DrawRotatedText(m_textCtrl->GetValue(), w/2 + 60, h/2 + 160, 90);
	m_gauge->SetValue(m_scrollBar->GetThumbPosition());

	int choice = m_choice->GetSelection();
	if (choice == 0) {
		wxPoint pts[5];
		pts[0] = wxPoint(37, 0);
		pts[1] = wxPoint(65, 65);
		pts[2] = wxPoint(0, 25);
		pts[3] = wxPoint(75, 25);
		pts[4] = wxPoint(5, 65);
		dc.SetBrush(wxBrush(colorDlg.GetColourData().GetColour(), wxBRUSHSTYLE_SOLID));
		dc.DrawPolygon(5, pts, w / 2 - 100, h / 2 - 130);

	}
	if (choice == 1) {
		dc.SetBrush(wxBrush(wxColour(200, 200, 200), wxBRUSHSTYLE_SOLID));
		wxPoint pts1[3];
		pts1[0] = wxPoint(w / 2 - 100 + 20, h / 2 - 130);
		pts1[1] = wxPoint(w / 2 - 140 + 20, h / 2 - 95);
		pts1[2] = wxPoint(w / 2 - 100 + 20, h / 2 - 60);
		dc.DrawSpline(3, pts1);
		pts1[0] = wxPoint(w / 2 - 100 + 20, h / 2 - 130);
		pts1[1] = wxPoint(w / 2 - 115 + 20, h / 2 - 95);
		pts1[2] = wxPoint(w / 2 - 100 + 20, h / 2 - 60);
		dc.DrawSpline(3, pts1);
	}
	if (choice == 2) {
		dc.SetBrush(wxBrush(wxColour(255, 255, 0), wxBRUSHSTYLE_SOLID));
		dc.DrawCircle(w / 2 - 100, h / 2 - 130, 30);
	}
}	