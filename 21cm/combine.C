void combine()
{
  ifstream* file;
  file = new ifstream[26];
  char str[200];

  for(int h=0; h<10; h++)
    {
      sprintf(str, "/home/adinhrnjic/root/macros/JLAB/code/rutherford/data/hshackle-1au-50-00%d.Spe", h);
      file[h].open(str);
    }

  for(int h=10; h<26; h++)
    {
      sprintf(str, "/home/adinhrnjic/root/macros/JLAB/code/rutherford/data/hshackle-1au-50-0%d.Spe", h);
      file[h].open(str);
    }

  ofstream out;
  out.open("hshackle-1au-50.Spe");
  TH1D * count = new TH1D("","",2047,0,2047);

  char tmp_str[200];
  for(int h=0; h<26; h++)
    {
      for(int i=0; i<2048;i++)
	{
	  file[h].getline(tmp_str,256);
	  double freq = atof(tmp_str);
	  if (freq >= 0)
	    {
	      count->Fill(i, freq);
	    }
	}
    }

  for(int i = 0; i<2048;i++)
    {
      out << count->GetBinContent(i) << endl;
    }
  count->Draw();
  c1->SaveAs("1au-50.pdf");
}
