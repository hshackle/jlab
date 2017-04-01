void inhomo_measure() {
  TCanvas *c1 = new TCanvas("c1", "Inhomogeneity Fit", 200, 10, 700 ,500);
  Double_t y[4] = {119.5,110.1,99.6, 89.9};
  Double_t x[4]= {120, 110.4, 100, 90};
  Double_t xerr[4] = {.2, .2, .2,.2};
  Double_t yerr[4] ={.07, .07, .07, .07};

  gr = new TGraphErrors(4, x, y, xerr, yerr);
  gr->Draw("AP");
  gr->Fit("pol1");
/*  gr->Fit("relativistic");*/
  gStyle->SetOptFit(1111);
};

int main(){
  inhomo_measure();
}
