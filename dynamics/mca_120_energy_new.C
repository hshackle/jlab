#include "Riostream.h"
#include "TGraph.h"

void mca_120_energy_new(){
 char tmp_str[1000];
  double freq;
  TCanvas *c1 = new TCanvas("c1", "Inhomogeneity Fit", 200, 10, 700, 500);
  Double_t x[2048];
  Double_t y[2048];
  Double_t xerr[2048];
  Double_t yerr[2048];
  std::vector<double> mean;
  std::vector<double> err;
  int bin = 0;
  data = new ifstream;
  data->open(Form("hshackle-4.4kV-120G-long.Spe"));
  
  while (1){

    data->getline(tmp_str, 256);
    freq = atof(tmp_str);

    x[bin] = bin*0.286286 - .591431;
    y[bin] = freq;
    yerr[bin] = TMath::Sqrt(freq);
    xerr[bin] = 0;
    bin += 1;

    if(!data->good()) break;
  }

  data->close();

  gr = new TGraphErrors(2048, x, y, xerr, yerr);
  auto axis = gr->GetXaxis();
  axis->SetLimits(345, 365);
  gr->SetMarkerStyle(21);
  gr->Draw("AP");
  TF1 *fit = new TF1("fit", "gaus", 340, 365);
  gr->Fit("fit", "R");
 mean.push_back(fit->GetParameter(1));
 err.push_back(fit->GetParError(1)); 

  gr->Clear();
 for (n=0;n< 2048;n++){
   x[bin] = 0;
   y[bin] = 0;
   xerr[bin] = 0;
   yerr[bin] = 0;
 }
  bin = 0;
  data = new ifstream;
  data->open(Form("hshackle-4.3kV-120G-long.Spe"));
  while (1){

    data->getline(tmp_str, 256);
    freq = atof(tmp_str);
    x[bin] = bin*0.286286 - .591431;
    y[bin] = freq;
    yerr[bin] = TMath::Sqrt(freq);
    xerr[bin] = 0;
    bin += 1;
    if(!data->good()) break;
  }

  data->close();
  gr1 = new TGraphErrors(2048, x, y, xerr, yerr);
  gr1->Fit("fit", "R");
 
 mean.push_back(fit->GetParameter(1));
 err.push_back(fit->GetParError(1)); 
 for (n=0;n< 2048;n++){
   x[bin] = 0;
   y[bin] = 0;
   xerr[bin] = 0;
   yerr[bin] = 0;
 }
  bin = 0;
  data = new ifstream;
  data->open(Form("hshackle-5.4kV-120G-long.Spe"));
  while (1){

    data->getline(tmp_str, 256);
    freq = atof(tmp_str);
    x[bin] = bin*0.286286 - .591431;
    y[bin] = freq;
    yerr[bin] = TMath::Sqrt(freq);
    xerr[bin] = 0;
    bin += 1;
    if(!data->good()) break;
  }

  data->close();
  gr2 = new TGraphErrors(2048, x, y, xerr, yerr);
  gr2->Fit("fit", "R");
 
 mean.push_back(fit->GetParameter(1));
 err.push_back(fit->GetParError(1)); 

 for (n=0;n< 2048;n++){
   x[bin] = 0;
   y[bin] = 0;
   xerr[bin] = 0;
   yerr[bin] = 0;
 }
  bin = 0;
  data = new ifstream;
  data->open(Form("hshackle-5.3kV-120G-long.Spe"));
  while (1){

    data->getline(tmp_str, 256);
    freq = atof(tmp_str);
    x[bin] = bin*0.286286 - .591431;
    y[bin] = freq;
    yerr[bin] = TMath::Sqrt(freq);
    xerr[bin] = 0;
    bin += 1;
    if(!data->good()) break;
  }

  data->close();
  gr3 = new TGraphErrors(2048, x, y, xerr, yerr);
  gr3->Fit("fit", "R");
 
 mean.push_back(fit->GetParameter(1));
 err.push_back(fit->GetParError(1)); 

 for (n=0;n< 2048;n++){
   x[bin] = 0;
   y[bin] = 0;
   xerr[bin] = 0;
   yerr[bin] = 0;
 }
  bin = 0;
  data = new ifstream;
  data->open(Form("hshackle-5.2kV-120G-long.Spe"));
  while (1){

    data->getline(tmp_str, 256);
    freq = atof(tmp_str);
    x[bin] = bin*0.286286 - .591431;
    y[bin] = freq;
    yerr[bin] = TMath::Sqrt(freq);
    xerr[bin] = 0;
    bin += 1;
    if(!data->good()) break;
  }

  data->close();
  gr4 = new TGraphErrors(2048, x, y, xerr, yerr);
  gr4->Fit("fit", "R");
 
 mean.push_back(fit->GetParameter(1));
 err.push_back(fit->GetParError(1)); 

 for (n=0;n< 2048;n++){
   x[bin] = 0;
   y[bin] = 0;
   xerr[bin] = 0;
   yerr[bin] = 0;
 }
  bin = 0;
  data = new ifstream;
  data->open(Form("hshackle-5.1kV-120G-long.Spe"));
  while (1){

    data->getline(tmp_str, 256);
    freq = atof(tmp_str);
    x[bin] = bin*0.286286 - .591431;
    y[bin] = freq;
    yerr[bin] = TMath::Sqrt(freq);
    xerr[bin] = 0;
    bin += 1;
    if(!data->good()) break;
  }

  data->close();
  gr5 = new TGraphErrors(2048, x, y, xerr, yerr);
  gr5->Fit("fit", "R");
 
 mean.push_back(fit->GetParameter(1));
 err.push_back(fit->GetParError(1)); 

 for (n=0;n< 2048;n++){
   x[bin] = 0;
   y[bin] = 0;
   xerr[bin] = 0;
   yerr[bin] = 0;
 }
  bin = 0;
  data = new ifstream;
  data->open(Form("hshackle-5.0kV-120G-long.Spe"));
  while (1){

    data->getline(tmp_str, 256);
    freq = atof(tmp_str);
    x[bin] = bin*0.286286 - .591431;
    y[bin] = freq;
    yerr[bin] = TMath::Sqrt(freq);
    xerr[bin] = 0;
    bin += 1;
    if(!data->good()) break;
  }

  data->close();
  gr6 = new TGraphErrors(2048, x, y, xerr, yerr);
  gr6->Fit("fit", "R");
 
 mean.push_back(fit->GetParameter(1));
 err.push_back(fit->GetParError(1)); 

 for (n=0;n< 2048;n++){
   x[bin] = 0;
   y[bin] = 0;
   xerr[bin] = 0;
   yerr[bin] = 0;
 }
  bin = 0;
  data = new ifstream;
  data->open(Form("hshackle-4.9kV-120G-long.Spe"));
  while (1){

    data->getline(tmp_str, 256);
    freq = atof(tmp_str);
    x[bin] = bin*0.286286 - .591431;
    y[bin] = freq;
    yerr[bin] = TMath::Sqrt(freq);
    xerr[bin] = 0;
    bin += 1;
    if(!data->good()) break;
  }

  data->close();
  gr7 = new TGraphErrors(2048, x, y, xerr, yerr);
  gr7->Fit("fit", "R");
 
 mean.push_back(fit->GetParameter(1));
 err.push_back(fit->GetParError(1)); 

for (n=0;n< 2048;n++){
   x[bin] = 0;
   y[bin] = 0;
   xerr[bin] = 0;
   yerr[bin] = 0;
 }
  bin = 0;
  data = new ifstream;
  data->open(Form("hshackle-4.8kV-120G-long.Spe"));
  while (1){

    data->getline(tmp_str, 256);
    freq = atof(tmp_str);
    x[bin] = bin*0.286286 - .591431;
    y[bin] = freq;
    yerr[bin] = TMath::Sqrt(freq);
    xerr[bin] = 0;
    bin += 1;
    if(!data->good()) break;
  }

  data->close();
  gr8 = new TGraphErrors(2048, x, y, xerr, yerr);
  gr8->Fit("fit", "R");
 
 mean.push_back(fit->GetParameter(1));
 err.push_back(fit->GetParError(1)); 
/*
for (n=0;n< 2048;n++){
   x[bin] = 0;
   y[bin] = 0;
   xerr[bin] = 0;
   yerr[bin] = 0;
 }
  bin = 0;
  data = new ifstream;
  data->open(Form("hshackle-4.7kV-120G-long.Spe"));
  while (1){

    data->getline(tmp_str, 256);
    freq = atof(tmp_str);
    x[bin] = bin*0.286286 - .591431;
    y[bin] = freq;
    yerr[bin] = TMath::Sqrt(freq);
    xerr[bin] = 0;
    bin += 1;
    if(!data->good()) break;
  }

  data->close();
  gr9 = new TGraphErrors(2048, x, y, xerr, yerr);
  gr9->Fit("fit", "R");
 
 mean.push_back(fit->GetParameter(1));
 err.push_back(fit->GetParError(1)); 
 */

for (n=0;n< 2048;n++){
   x[bin] = 0;
   y[bin] = 0;
   xerr[bin] = 0;
   yerr[bin] = 0;
 }
  bin = 0;
  data = new ifstream;
  data->open(Form("hshackle-4.6kV-120G-long.Spe"));
  while (1){

    data->getline(tmp_str, 256);
    freq = atof(tmp_str);
    x[bin] = bin*0.286286 - .591431;
    y[bin] = freq;
    yerr[bin] = TMath::Sqrt(freq);
    xerr[bin] = 0;
    bin += 1;
    if(!data->good()) break;
  }

  data->close();
  gr10 = new TGraphErrors(2048, x, y, xerr, yerr);
  gr10->Fit("fit", "R");
 
 mean.push_back(fit->GetParameter(1));
 err.push_back(fit->GetParError(1)); 

for (n=0;n< 2048;n++){
   x[bin] = 0;
   y[bin] = 0;
   xerr[bin] = 0;
   yerr[bin] = 0;
 }
  bin = 0;
  data = new ifstream;
  data->open(Form("hshackle-4.5kV-120G-long.Spe"));
  while (1){

    data->getline(tmp_str, 256);
    freq = atof(tmp_str);
    x[bin] = bin*0.286286 - .591431;
    y[bin] = freq;
    yerr[bin] = TMath::Sqrt(freq);
    xerr[bin] = 0;
    bin += 1;
    if(!data->good()) break;
  }

  data->close();
  gr11 = new TGraphErrors(2048, x, y, xerr, yerr);
  gr11->Fit("fit", "R");
 
 mean.push_back(fit->GetParameter(1));
 err.push_back(fit->GetParError(1)); 



 double total_mean = TMath::Mean(mean.begin(), mean.end());
 double rms = TMath::RMS(mean.begin(), mean.end());
 double total_err = 0;


 cout << total_mean << endl;

 for (double n : err){
   total_err += n*n;
 }
 total_err = total_err/11;
 total_err = TMath::Sqrt(total_err + rms*rms/11);
 cout << total_err << endl;
}


