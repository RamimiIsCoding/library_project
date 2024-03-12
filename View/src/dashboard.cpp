#include "dashboard.hpp"
dashboard::dashboard(wxWindow* Parent):wxPanel(Parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE){
     wxBoxSizer* dashboardSizer = new wxBoxSizer(wxVERTICAL);
     wxStaticText* lblDashboardTitle = new wxStaticText(this, wxID_ANY, "Dashboard");
     
    section* section1 = new section(this);
    section* section2 = new section(this);   
    section* section3 = new section(this);

        dashboardSizer->Add(lblDashboardTitle, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
        dashboardSizer->Add(section1, 1, wxEXPAND | wxALL, 10);
        dashboardSizer->Add(section2, 1, wxEXPAND | wxALL, 10);
        dashboardSizer->Add(section3, 1, wxEXPAND | wxALL, 10);
        this->SetSizerAndFit(dashboardSizer);        
}