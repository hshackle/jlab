void beam_profile()
{
  double counts[16], angle[16];
  angle[0] = -9;
  angle[1] = -8;
  angle[2] = -7;
  angle[3] = -6;
  angle[4] = -5;
  angle[5] = -4;
  angle[6] = -3;
  angle[7] = -2;
  angle[8] = -1;
  angle[9] = 0;
  angle[10] = 1;
  angle[11] = 2;
  angle[12] = 3;
  angle[13] = 4;
  angle[14] = 5;
  angle[15] = 6;

  for (int i=0; i<16; i++){
    angle[i] = angle[i] + 1.995;
  }
  
  counts[0] = 2;
  counts[1] = 219;
  counts[2] = 1016;
  counts[3] = 2304;
  counts[4] = 3572;
  counts[5] = 5366;
  counts[6] = 5968;
  counts[7] = 6121;
  counts[8] = 5812;
  counts[9] = 5207;
  counts[10] = 3898;
  counts[11] = 2412;
  counts[12] = 1480;
  counts[13] = 886;
  counts[14] = 195;
  counts[15] = 40;

  double rate[16], rateerror[16], angleerror[16];
  for (int i=0; i<16; i++)
    {
      rate[i] = counts[i]/30;
      rateerror[i] = sqrt(counts[i])/30;
      angleerror[i] = 1;
    }

  gStyle->SetOptFit(1100);
  TGraphErrors * ratehist = new TGraphErrors(16, angle, rate, angleerror, rateerror);
  TF1 *triangle = new TF1("triangle", "[1]*(1-TMath::Abs(x-[2])/[0])*0.5*(TMath::Sign(1,(-TMath::Abs(x-[2]) + [0]) )+1)", -30, 30);
  triangle->SetParameter(0, 6);
  triangle->SetParameter(1, 200);
  triangle->SetParameter(2, 0);
  triangle->SetParName(0, "Base Half-Width");
  triangle->SetParName(1, "Height");
  triangle->SetParName(2, "Center");
  ratehist->Draw("AP");
  ratehist->Fit("triangle");
  ratehist->SetTitle("Beam Profile");
  ratehist->GetXaxis()->SetTitle("Howitzer Angle [#theta]");
  ratehist->GetYaxis()->SetTitle("Count Rate [1/s]");
}
