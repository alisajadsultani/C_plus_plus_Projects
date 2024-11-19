#pragma once
#include <wx/wx.h>
#include "MainFrame.h"


class NewWindow : public wxFrame
{
public:
	NewWindow(const wxString& title);
private:
	void CloseWindow(wxCommandEvent& evt);
};

