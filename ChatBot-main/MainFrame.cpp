#include "MainFrame.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <wx/wx.h>
#include <wx/menu.h>
#include <wx/bitmap.h>
#include <wx/statbmp.h>
#include <wx/hyperlink.h>
#include "NewWindow.h"
#include <wx/icon.h>
#include <wx/graphics.h>
#include <wx/textctrl.h>
#include <wx/clipbrd.h> 

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	wxImage::AddHandler(new wxPNGHandler());
	wxIcon icon("robot.png", wxBITMAP_TYPE_PNG);
	SetIcon(icon);

	Bind(wxEVT_PAINT, &MainFrame::OnPaint, this);

	panel = new wxPanel(this);
	panel->SetBackgroundColour(*wxWHITE);

	MenuBarList();
	CreateControls();
	headlineTextShow();
	BindEventHandlers();
}

void MainFrame::headlineTextShow()
{
	wxFont headlineFont(wxFontInfo(wxSize(0, 30)).Bold());
	wxString headline = wxT("Welcome to Sajad's ChatBot!");
	headlineText = new wxStaticText(panel, wxID_ANY, headline, wxPoint(0, 40), wxSize(700, -1), wxALIGN_CENTER_HORIZONTAL);
	headlineText->SetFont(headlineFont);

	wxFont headlineFontTwo(wxFontInfo(wxSize(0, 20)).Bold());
	wxString dis2 = wxT("This Chatbot provides detailed information\n about famous movies or games you inquire about.");
	headlineTextSecond = new wxStaticText(panel, wxID_ANY, dis2, wxPoint(0, 100), wxSize(700, -1), wxALIGN_CENTER_HORIZONTAL);
	headlineTextSecond->SetFont(headlineFontTwo);

	wxFont headlineFontThree(wxFontInfo(wxSize(0, 30)).Bold());
	wxString displaying = wxT("Choose one of the below options");
	headlineTextThird = new wxStaticText(panel, wxID_ANY, displaying, wxPoint(0, 40), wxSize(700, -1), wxALIGN_CENTER_HORIZONTAL);
	headlineTextThird->SetFont(headlineFontThree);

	headlineText->Show();
	headlineTextSecond->Show();
	headlineTextThird->Hide();
}

void MainFrame::CreateControls()
{

	wxColour lightBlue(173, 216, 230);
	next = new wxButton(panel, wxID_ANY, "Next", wxPoint(550, 470), wxSize(80, 50));
	next->SetBackgroundColour(lightBlue);
	end = new wxButton(panel, wxID_ANY, "End", wxPoint(550, 420), wxSize(80, 50));
	end->SetBackgroundColour(lightBlue);
	movieList = new wxButton(panel, wxID_ANY, "Movie List", wxPoint(550, 370), wxSize(80, 50));
	movieList->SetBackgroundColour(lightBlue);
	gameList = new wxButton(panel, wxID_ANY, "Game List", wxPoint(550, 470), wxSize(80, 50));
	gameList->SetBackgroundColour(lightBlue);
	startOver = new wxButton(panel, wxID_ANY, "Start Over", wxPoint(550, 320), wxSize(80, 50));
	startOver->SetBackgroundColour(lightBlue);
	/*
	//Loading and displaying the image
	wxJPEGHandler* handler = new wxJPEGHandler;
	wxImage::AddHandler(handler);
	wxImage bitmap(wxT("Spiderman.jpg"), wxBITMAP_TYPE_JPEG);

	if (bitmap.IsOk())
	{
		bitmap.Rescale(210, 150);
		wxBitmap imageControl(bitmap);
		wxStaticBitmap* image = new wxStaticBitmap(panel, wxID_ANY, imageControl, wxPoint(20, 100), wxSize(imageControl.GetWidth(), imageControl.GetHeight()));
	}
	*/
	HideShow();
}

void MainFrame::BindEventHandlers()
{
	next->Bind(wxEVT_BUTTON, &MainFrame::EnterForNew, this);
	end->Bind(wxEVT_BUTTON, &MainFrame::CloseTheWindow, this);
	movieList->Bind(wxEVT_BUTTON, &MainFrame::DisplayMovieName, this);
	gameList->Bind(wxEVT_BUTTON, &MainFrame::DisplayGameName, this);
	startOver->Bind(wxEVT_BUTTON, &MainFrame::StartOverWindow, this);
}

void MainFrame::MenuBarList()
{
	wxMenu* menuFile = new wxMenu;
	menuFile->Append(ID_EXIT, "&Exit", "Quit the Application");

	wxMenu* menuAbout = new wxMenu;
	menuAbout->Append(ID_ABOUT, "&About", "About the ChatBot");

	wxMenu* menuEdit = new wxMenu;
	menuEdit->Append(ID_COPY, "&Copy\tCtrl-C", "Copy the link to the IMDB webiste");

	wxMenuBar* menuBar = new wxMenuBar;
	menuBar->Append(menuFile, "&File");
	menuBar->Append(menuAbout, "&Help");
	menuBar->Append(menuEdit, "&Edit");

	SetMenuBar(menuBar);
	CreateStatusBar();

	Bind(wxEVT_MENU, &MainFrame::OnButtonClicked, this, ID_ABOUT);
	Bind(wxEVT_MENU, &MainFrame::CloseTheWindow, this, ID_EXIT);
	Bind(wxEVT_MENU, &MainFrame::OnCopy, this, ID_COPY);
}

//Copy link
void MainFrame::OnCopy(wxCommandEvent& evt)
{
	linkTextCtrl = new wxTextCtrl(this, wxID_ANY, "https://www.imdb.com/", wxDefaultPosition, wxDefaultSize);
	if (wxTheClipboard->Open())
	{
		wxTheClipboard->SetData(new wxTextDataObject(linkTextCtrl->GetValue()));
		wxTheClipboard->Close();
	}
}

void MainFrame::HideShow()
{
	movieList->Hide();
	gameList->Hide();
	startOver->Hide();
}

//New window function
void MainFrame::OnButtonClicked(wxCommandEvent& evt)
{
	NewWindow* newWindow = new NewWindow("About");
	newWindow->SetClientSize(720, 320);
	newWindow->Center();
	newWindow->Show(true);
	
}

void MainFrame::StartOverWindow(wxCommandEvent& evt)
{
	int response = wxMessageBox("Starting over, are you sure?", "Start Over", wxYES_NO | wxNO_DEFAULT, this);
	if (response == wxYES)
	{
		HideAllWidgets();

		startOver->Move(wxPoint(550, 320));

		end->Show();
		next->Show();

		next->Unbind(wxEVT_BUTTON, &MainFrame::EnterForNew, this);
		end->Unbind(wxEVT_BUTTON, &MainFrame::CloseTheWindow, this);

		next->Bind(wxEVT_BUTTON, &MainFrame::EnterForNew, this);
		end->Bind(wxEVT_BUTTON, &MainFrame::CloseTheWindow, this);

		// Force the panel to update its layout
		panel->Layout();
	}
}


void MainFrame::EnterForNew(wxCommandEvent& evt)
{
	next->Hide();
	headlineText->Hide();
	headlineTextSecond->Hide();
	headlineTextThird->Show();
	
	movieList->Show();
	gameList->Show();
	startOver->Show();
	panel->Layout();
}

void MainFrame::CloseTheWindow(wxCommandEvent& evt)
{
	int response = wxMessageBox("Closing the window, are you sure?", "Close", wxYES_NO | wxNO_DEFAULT, this);
	if (response == wxYES)
	{
		Close(true);
	}
}


void MainFrame::DisplayMovieName(wxCommandEvent& evt)
{
	MovieList();
}

void MainFrame::DisplayGameName(wxCommandEvent& evt)
{
	GameList();
}

void MainFrame::MovieList()
{
	gameList->Hide();
	headlineTextThird->Hide();

	startOver->Move(wxPoint(550, 320));

	wxFont headlineFont(wxFontInfo(wxSize(0, 30)).Bold());
	wxString headline = wxT("List of Top 10 Movies of all the time!");
	headlineTextMovie = new wxStaticText(panel, wxID_ANY, headline, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
	headlineTextMovie->SetFont(headlineFont);

	std::vector<std::pair<wxString, wxString>> movies{
		{"The Godfather", "https://www.imdb.com/title/tt0068646/?ref_=ls_t_1"},
		{"The Shawshank Redemption", "https://www.imdb.com/title/tt0111161/?ref_=ls_t_2"},
		{"The Godfather Part II", "https://www.imdb.com/title/tt0071562/?ref_=ls_t_13"},
		{"Star Wars: Episode IV - A New Hope", "https://www.imdb.com/title/tt0076759/?ref_=ls_t_20"},
		{"Gladiator", "https://www.imdb.com/title/tt0172495/?ref_=ls_t_34"},
		{"The Lord of the Rings: The Return of the King", "https://www.imdb.com/title/tt0167260/?ref_=ls_t_33"},
		{"Titanic", "https://www.imdb.com/title/tt0120338/?ref_=ls_t_35"},
		{"Jurassic Park", "https://www.imdb.com/title/tt0107290/?ref_=ls_t_60"},
		{"Braveheart", "https://www.imdb.com/title/tt0112573/?ref_=ls_t_58"},
		{"Spider Man No Way Home", "https://www.imdb.com/title/tt10872600/"},
	};

	wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
	vbox->Add(headlineTextMovie, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP, 35);

	wxFont linkFont(wxFontInfo(wxSize(0, 18)).Bold());
	for (const auto& movie : movies)
	{
		wxHyperlinkCtrl* linkMovie = new wxHyperlinkCtrl(panel, wxID_ANY, movie.first, movie.second);
		linkMovie->SetFont(linkFont);
		vbox->Add(linkMovie, 0, wxALIGN_LEFT | wxTOP | wxALL, 12);
		movieListLinks.push_back(linkMovie);
	}

	panel->SetSizer(vbox);
	panel->Layout();
}

void MainFrame::GameList()
{
	movieList->Hide();
	headlineTextThird->Hide();

	startOver->Move(wxPoint(550, 370));

	wxFont headlineFont(wxFontInfo(wxSize(0, 30)).Bold());
	wxString headline = wxT("List of Top 10 Games of all the time!");
	headlineTextGame = new wxStaticText(panel, wxID_ANY, headline, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
	headlineTextGame->SetFont(headlineFont);

	std::vector<std::pair<wxString, wxString>> games = {
		{"God of War", "https://www.imdb.com/title/tt5838588/"},
		{"Red Dead Redemption II", "https://www.imdb.com/title/tt6161168/?ref_=sr_t_1"},
		{"Baldur's Gate III", "https://www.imdb.com/title/tt13258344/?ref_=sr_t_2"},
		{"The Last of Us", "https://www.imdb.com/title/tt2140553/?ref_=sr_t_3"},
		{"God of War Ragnarok", "https://www.imdb.com/title/tt13119450/?ref_=sr_t_5"},
		{"The Witcher 3: Wild Hunt", "https://www.imdb.com/title/tt2993508/?ref_=sr_t_6"},
		{"Metal Gear Solid", "https://www.imdb.com/title/tt0180825/?ref_=sr_t_7"},
		{"Elden Ring", "https://www.imdb.com/title/tt10562854/?ref_=sr_t_22"},
		{"Grand Theft Auto V", "https://www.imdb.com/title/tt2103188/?ref_=sr_t_11"},
		{"Bloodborne: The Old Hunters", "https://www.imdb.com/title/tt5032376/?ref_=sr_t_19"}
	};

	wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
	vbox->Add(headlineTextGame, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP, 35);

	wxFont linkFont(wxFontInfo(wxSize(0, 18)).Bold());
	for (const auto& game : games)
	{
		wxHyperlinkCtrl* linkGame = new wxHyperlinkCtrl(panel, wxID_ANY, game.first, game.second);
		linkGame->SetFont(linkFont);
		vbox->Add(linkGame, 0, wxALIGN_LEFT | wxTOP | wxALL, 12);
		gameListLinks.push_back(linkGame);
	}

	panel->SetSizer(vbox);
	panel->Layout();
}

void MainFrame::HideAllWidgets()
{
	// Hide all existing widgets
	if (headlineText) headlineText->Show();
	if (headlineTextSecond) headlineTextSecond->Show();
	if (headlineTextThird) headlineTextThird->Hide();
	if (headlineTextGame) headlineTextGame->Hide();
	if (headlineTextMovie) headlineTextMovie->Hide();
	if (movieList) movieList->Hide();
	if (gameList) gameList->Hide();
	if (startOver) startOver->Hide();
	//if (staticText) staticText->Hide();

	// Hide all game list links

	for (auto& linkGame : gameListLinks)
	{
		linkGame->Hide();
	}

	for (auto& linkMovie : movieListLinks)
	{
		linkMovie->Hide();
	}
	
}

void MainFrame::OnPaint(wxPaintEvent& evt)
{
	wxPaintDC dc(this);
	wxGraphicsContext* gc = wxGraphicsContext::Create(dc);

	if (gc)
	{
		gc->SetBrush(*wxBLUE_BRUSH);
		gc->DrawRectangle(100, 100, 200, 200);

		gc->SetPen(*wxRED_PEN);
		gc->StrokeLine(100, 100, 300, 300);

		delete gc;
	}
}