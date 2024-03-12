#include "frame.hpp"
#include "dashboard.hpp"
    MainFrame::MainFrame() : wxFrame(nullptr, wxID_ANY, "Mon lecteur de musique", wxDefaultPosition, wxSize(1000, 800)) {
        aside* test = new aside(this) ;
        dashboard* dash = new dashboard(this);
        wxBoxSizer* frameSizer = new wxBoxSizer(wxHORIZONTAL);
        frameSizer->Add(test,1, wxEXPAND);
        frameSizer->Add(dash, 4, wxEXPAND);
        SetSizerAndFit(frameSizer);
    }