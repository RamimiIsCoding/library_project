#include "frame.hpp"

class MyApp : public wxApp {
public:
    virtual bool OnInit() {
        MainFrame* frame = new MainFrame();
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);
// #include <wx/wx.h>

// class MySecondFrame : public wxFrame {
// public:
//     MySecondFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
//         : wxFrame(NULL, wxID_ANY, title, pos, size) {}
// };

// class MyMainFrame : public wxFrame {
// public:
//     MyMainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

// private:
//     void OnOpenSecondFrame(wxCommandEvent& event);

//     wxButton* m_button;
//     MySecondFrame* m_secondFrame;
//     DECLARE_EVENT_TABLE()
// };

// BEGIN_EVENT_TABLE(MyMainFrame, wxFrame)
//     EVT_BUTTON(wxID_ANY, MyMainFrame::OnOpenSecondFrame)
// END_EVENT_TABLE()

// MyMainFrame::MyMainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
//     : wxFrame(NULL, wxID_ANY, title, pos, size) {
//     // Création du bouton
//     m_button = new wxButton(this, wxID_ANY, "Ouvrir la deuxième fenêtre", wxPoint(10, 10), wxDefaultSize);
//     m_secondFrame = nullptr;
// }

// void MyMainFrame::OnOpenSecondFrame(wxCommandEvent& event) {
//     if (!m_secondFrame) {
//         m_secondFrame = new MySecondFrame("Deuxième fenêtre", wxPoint(100, 100), wxSize(300, 200));
//         m_secondFrame->Show(true);
//     }
// }

// class MyApp : public wxApp {
// public:
//     virtual bool OnInit();
// };

// wxIMPLEMENT_APP(MyApp);

// bool MyApp::OnInit() {
//     MyMainFrame* frame = new MyMainFrame("Première fenêtre", wxPoint(50, 50), wxSize(400, 300));
//     frame->Show(true);
//     return true;
// }