
#include "App.h"
#include "MainFrame.h"
#include <iostreaM>


wxIMPLEMENT_APP(App);


bool App::OnInit()
{
	MainFrame* mainFrame = new MainFrame("Movie and Game Assistant");
	mainFrame->SetClientSize(700, 550);
	mainFrame->Center();
	mainFrame->Show();
	return true;
}
