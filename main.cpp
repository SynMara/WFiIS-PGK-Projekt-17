#define NDEBUG
#include <wx/wx.h>
#include "MyProject1Frame.h"

class MyApp : public wxApp {

public:

	virtual bool OnInit();
	virtual int OnExit() { return 0; }

};

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	MyProject1Frame *mainFrame = new MyProject1Frame(NULL);
	mainFrame->Show(true);
	SetTopWindow(mainFrame);

	return true;
}