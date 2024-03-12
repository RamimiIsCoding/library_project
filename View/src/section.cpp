#include "section.hpp"
section::section(wxWindow* Parent ) :  wxPanel(Parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE){
    wxStaticText* lblMembre = new wxStaticText(this, wxID_ANY, "Membre");
    wxFont font(18, wxFONTFAMILY_DEFAULT,  wxFONTWEIGHT_BOLD, wxFONTWEIGHT_NORMAL);
    lblMembre->SetFont(font);
    wxGrid *List_membre = new wxGrid(this, wxID_ANY);
        List_membre->CreateGrid(3, 3); // 3 lignes, 3 colonnes
        List_membre->SetColLabelValue(0, "nom");
        List_membre->SetColLabelValue(1, "prenom");
        List_membre->SetColLabelValue(2, "numero");
        List_membre->SetCellHighlightPenWidth(0);
        // Remplir le tableau avec des valeurs
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                List_membre->SetReadOnly(row,col);
                List_membre->SetCellValue(row, col, wxString::Format("(%d,%d)", row, col));
            }
        }
        wxBoxSizer* sectionSizer = new wxBoxSizer(wxVERTICAL);
        sectionSizer->Add(lblMembre, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
        sectionSizer->Add(List_membre, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
        this->SetSizerAndFit(sectionSizer);
    
}   