#pragma once
#include <wx/wx.h>
#include "NewWindow.h"
#include <wx/hyperlink.h>

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);

private:
	void CreateControls();
	void BindEventHandlers();
	void MenuBarList();

	void EnterForNew(wxCommandEvent& evt);

	//Closing the window
	void CloseTheWindow(wxCommandEvent& evt);

	//Movie and Game lists
	void DisplayMovieName(wxCommandEvent& evt);
	void DisplayGameName(wxCommandEvent& evt);
	void MovieList();
	void GameList();

	void HideShow();

	//Header texts
	void headlineTextShow();
	void HideShowHeadlines();

	//New window for About button
	void OnButtonClicked(wxCommandEvent& evt);
	//Start Over
	void StartOverWindow(wxCommandEvent& evt);

	void HideAllWidgets();

	void OnPaint(wxPaintEvent& evt);


	//Copy and Paste
	void OnCopy(wxCommandEvent& evt);

	wxPanel* panel;
	wxButton* next;
	wxButton* end;
	wxButton* movieList;
	wxButton* gameList;
	wxButton* startOver;

	std::vector<wxHyperlinkCtrl*> gameListLinks;
	std::vector<wxHyperlinkCtrl*> movieListLinks;

	wxCheckListBox* checkListBox;
	wxStaticText* headlineText;
	wxStaticText* headlineTextSecond;
	wxStaticText* headlineTextThird;
	wxStaticText* headlineTextMovie;
	wxStaticText* headlineTextGame;

	wxTextCtrl* linkTextCtrl;
};

enum
{
	ID_EXIT,
	ID_ABOUT,
	ID_COPY
};