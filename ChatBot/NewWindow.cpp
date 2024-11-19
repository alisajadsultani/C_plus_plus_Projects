#include "NewWindow.h"
#include <iostream>
#include <wx/wx.h>
#include <wx/image.h>
#include <wx/icon.h>

NewWindow::NewWindow(const wxString& title): wxFrame(nullptr, wxID_ANY, title)
{

	wxImage::AddHandler(new wxPNGHandler());
	wxIcon icon("robot.png", wxBITMAP_TYPE_PNG);
	SetIcon(icon);

	wxPanel* panel = new wxPanel(this);
	wxFont headlineFont(wxFontInfo(wxSize(0, 15)).Bold());
	wxString AboutChatBot = wxT("Welcome to Sajad's ChatBot, a comprehensive guide to the top 10 movies and games of all time! Designed with user engagement in mind,"
		"this chatbot provides detailed information on the most iconic and critically acclaimed films and video games. "
		"Whether you're a film aficionado looking for timeless classics or a gaming enthusiast searching for the best titles ever released, Sajad's ChatBot has got you covered."
		"Through an intuitive and user - friendly interface, you can explore curated lists, read brief descriptions, and even access external links for more in - depth information."
		"This chatbot not only enhances your knowledge of entertainment history but also helps you discover new favorites to watch and play."
		"Dive into the world of cinema and gaming with Sajad's ChatBot and experience the ultimate entertainment journey.");

	wxStaticText* text = new wxStaticText(panel, wxID_ANY, AboutChatBot, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
	text->SetFont(headlineFont);

	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

	// Add the text to the sizer with proportion 1 and wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL flag
	// Also, add border with 20-pixel gap
	sizer->Add(text, 1, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxTOP, 20);

	//Creating and binding Close button
	wxColour lightBlue(173, 216, 230);
	wxButton* button = new wxButton(panel, wxID_ANY, "Close");
	sizer->Add(button, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 45);
	button->SetBackgroundColour(lightBlue);
	//buttonSizer->Add(button, 0, wxALIGN_RIGHT | wxALL, 10);
	button->Bind(wxEVT_BUTTON, &NewWindow::CloseWindow, this);

	// Set the sizer for the panel
	panel->SetSizer(sizer);
	// Fit the sizer's contents into the panel
	panel->Layout();
}


void NewWindow::CloseWindow(wxCommandEvent& evt)
{
	Close(true);
}

