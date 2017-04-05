void rel() {
  TCanvas *c1 = new TCanvas("c1", "Inhomogeneity Fit", 200, 10, 700 ,500);
  TF1 *fit1 = new TF1("fit1", "TMath::Sqrt(x*x*20.3*20.3*.309777*.309777 + 554.032*554.032) - 554.032", 0,140);
  fit1->GetYaxis()->SetTitle("Kinetic Enery [kEv]");
  fit1->GetXaxis()->SetTitle("Momentum [");
  fit1->SetTitle();
  fit1->Draw();
  TF1 *fit2 = new TF1("fit2", ".035*x*x", 0,140);
  fit2->SetLineColor(4);
  fit2->Draw("SAME");
};

int main(){
  rel();
}
