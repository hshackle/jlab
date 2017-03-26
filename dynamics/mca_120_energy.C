#include "Riostream.h"
#include "TGraph.h"

void mca_120_energy(){
 char tmp_str[1000];
  double freq;
  std::vector<double> mean;
  std::vector<double> err;
  int bin = 0;
  data = new ifstream;
  data->open(Form("hshackle-4.4kV-120G-long.Spe"));
  
  TH1F *h1 = new TH1F("Data", "Electron Count Rate", 150, 340,370);
  while (1){

    data->getline(tmp_str, 256);
    freq = atof(tmp_str);

    h1->Fill(bin*0.286286 - .591431, freq);
    bin += 1;

    if(!data->good()) break;
  }

  data->close();

 h1->Fit("gaus");
 TF1 *fit = h1->GetFunction("gaus");
 mean.push_back(fit->GetParameter(1));
 err.push_back(fit->GetParError(1)); 

 bin = 0;
  data = new ifstream;
  data->open(Form("hshackle-4.3kV-120G-long.Spe"));
  h1->Reset();
  while (1){

    data->getline(tmp_str, 256);
    freq = atof(tmp_str);

    h1->Fill(bin*0.286286 - .591431, freq);
    bin += 1;

    if(!data->good()) break;
  }

  data->close();

 h1->Fit("gaus");
 TF1 *fit1 = h1->GetFunction("gaus");
 mean.push_back(fit1->GetParameter(1));
 err.push_back(fit1->GetParError(1)); 
  bin = 0;
  data = new ifstream;
  data->open(Form("hshackle-5.4kV-120G-long.Spe"));
  h1->Reset();
  while (1){

    data->getline(tmp_str, 256);
    freq = atof(tmp_str);

    h1->Fill(bin*0.286286 - .591431, freq);
    bin += 1;

    if(!data->good()) break;
  }

  data->close();

 h1->Fit("gaus");
 TF1 *fit2 = h1->GetFunction("gaus");
 mean.push_back(fit2->GetParameter(1));
err.push_back(fit2->GetParError(1)); 
 
  bin = 0;
  data = new ifstream;
  data->open(Form("hshackle-5.3kV-120G-long.Spe"));
  h1->Reset();
  
  while (1){

    data->getline(tmp_str, 256);
    freq = atof(tmp_str);

    h1->Fill(bin*0.286286 - .591431, freq);
    bin += 1;

    if(!data->good()) break;
  }

  data->close();

 h1->Fit("gaus");
 TF1 *fit3 = h1->GetFunction("gaus");
 mean.push_back(fit3->GetParameter(1));
 err.push_back(fit3->GetParError(1));
  bin = 0;
  data = new ifstream;
  data->open(Form("hshackle-5.2kV-120G-long.Spe"));
  h1->Reset();
  
  while (1){

    data->getline(tmp_str, 256);
    freq = atof(tmp_str);

    h1->Fill(bin*0.286286 - .591431, freq);
    bin += 1;

    if(!data->good()) break;
  }

  data->close();

 h1->Fit("gaus");
 TF1 *fit4 = h1->GetFunction("gaus");
 mean.push_back(fit4->GetParameter(1));
 err.push_back(fit4->GetParError(1));

  bin = 0;
  data = new ifstream;
  data->open(Form("hshackle-5.1kV-120G-long.Spe"));
  h1->Reset();
  
  while (1){

    data->getline(tmp_str, 256);
    freq = atof(tmp_str);

    h1->Fill(bin*0.286286 - .591431, freq);
    bin += 1;

    if(!data->good()) break;
  }

  data->close();

 h1->Fit("gaus");
 TF1 *fit5 = h1->GetFunction("gaus");
 mean.push_back(fit5->GetParameter(1));
 err.push_back(fit5->GetParError(1));

  bin = 0;
  data = new ifstream;
  data->open(Form("hshackle-4.5kV-120G-long.Spe"));
  h1->Reset();
  
  while (1){

    data->getline(tmp_str, 256);
    freq = atof(tmp_str);

    h1->Fill(bin*0.286286 - .591431, freq);
    bin += 1;

    if(!data->good()) break;
  }

  data->close();

 h1->Fit("gaus");
 TF1 *fit6 = h1->GetFunction("gaus");
 mean.push_back(fit6->GetParameter(1));
 err.push_back(fit6->GetParError(1));

  bin = 0;
  data = new ifstream;
  data->open(Form("hshackle-4.6kV-120G-long.Spe"));
  h1->Reset();
  
  while (1){

    data->getline(tmp_str, 256);
    freq = atof(tmp_str);

    h1->Fill(bin*0.286286 - .591431, freq);
    bin += 1;

    if(!data->good()) break;
  }

  data->close();

 h1->Fit("gaus");
 TF1 *fit7 = h1->GetFunction("gaus");
 mean.push_back(fit7->GetParameter(1));
 err.push_back(fit7->GetParError(1));

  /*bin = 0;
  data = new ifstream;
  data->open(Form("hshackle-4.7kV-120G-long.Spe"));
  h1->Reset();
  
  while (1){

    data->getline(tmp_str, 256);
    freq = atof(tmp_str);
    cout << freq << endl;

    h1->Fill(bin*0.286286 - .591431, freq);
    bin += 1;

    if(!data->good()) break;
  }

  data->close();

 h1->Fit("gaus");
 TF1 *fit10 = h1->GetFunction("gaus");
 mean.push_back(fit10->GetParameter(1));
 err.push_back(fit10->GetParError(1));
*/
  bin = 0;
  data = new ifstream;
  data->open(Form("hshackle-4.8kV-120G-long.Spe"));
  h1->Reset();
  
  while (1){

    data->getline(tmp_str, 256);
    freq = atof(tmp_str);

    h1->Fill(bin*0.286286 - .591431, freq);
    bin += 1;

    if(!data->good()) break;
  }

  data->close();

 h1->Fit("gaus");
 TF1 *fit8 = h1->GetFunction("gaus");
 mean.push_back(fit8->GetParameter(1));
 err.push_back(fit8->GetParError(1));

  bin = 0;
  data = new ifstream;
  data->open(Form("hshackle-4.9kV-120G-long.Spe"));
  h1->Reset();
  
  while (1){

    data->getline(tmp_str, 256);
    freq = atof(tmp_str);

    h1->Fill(bin*0.286286 - .591431, freq);
    bin += 1;

    if(!data->good()) break;
  }

  data->close();

 h1->Fit("gaus");
 TF1 *fit9 = h1->GetFunction("gaus");
 mean.push_back(fit9->GetParameter(1));
 err.push_back(fit9->GetParError(1));

  bin = 0;
  data = new ifstream;
  data->open(Form("hshackle-5.0kV-120G-long.Spe"));
  h1->Reset();
  
  while (1){

    data->getline(tmp_str, 256);
    freq = atof(tmp_str);

    h1->Fill(bin*0.286286 - .591431, freq);
    bin += 1;

    if(!data->good()) break;
  }

  data->close();

 h1->Fit("gaus");
 TF1 *fit11 = h1->GetFunction("gaus");
 mean.push_back(fit11->GetParameter(1));
 err.push_back(fit11->GetParError(1));

 double total_mean = TMath::Mean(mean.begin(), mean.end());
 double rms = TMath::RMS(mean.begin(), mean.end());
 double total_err = 0;
/*
 for (double n : mean){
   total_mean += n;
 }
 total_mean = total_mean/12;
 */
 cout << total_mean << endl;

 for (double n : err){
   total_err += n*n;
 }
 total_err = total_err/11;
 total_err = TMath::Sqrt(total_err + rms*rms/11);
 cout << total_err << endl;
}


