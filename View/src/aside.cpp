#include "aside.hpp"
aside::aside(wxWindow* Parent) : wxPanel(Parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE) {

    wxBoxSizer* asideSizer = new wxBoxSizer(wxVERTICAL);

    wxStaticText* lblTitle = new wxStaticText(this, wxID_ANY, "Titres de chansons:");
    asideSizer->Add(lblTitle, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);

    wxListBox* lstTitles = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, nullptr, wxLB_SINGLE);
    std::vector<std::string> label = {"membre", "book", "emprunt"};
    for (const auto& title : label) {
        lstTitles->Append(title);
    }
    asideSizer->Add(lstTitles, 1, wxEXPAND );

    this->SetSizer(asideSizer);
}
