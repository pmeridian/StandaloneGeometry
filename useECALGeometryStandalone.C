{
  gSystem->Load("libFWCoreFWLite");
  gSystem->Load("libDataFormatsEcalDetId");
  gSystem->Load("libDataFormatsGeometryVector");
  AutoLibraryLoader::enable();
  gROOT->ProcessLine(".L ECALGeometry.cc++");
  TFile *f=TFile::Open("caloGeometry.root");
  ECALGeometry* geom=ECALGeometry::getGeometry(f);
  EBDetId anEBDetId(35,176);
  GlobalPoint myPos= geom->getPosition(anEBDetId);
  std::cout << "ETA,PHI:" << myPos.eta() << "," << myPos.phi() << std::endl;

  EEDetId anEEDetId(5,51,1);
  GlobalPoint myPosEE= geom->getPosition(anEEDetId);
  std::cout << "ETA,PHI:" << myPosEE.eta() << "," << myPosEE.phi() << std::endl;
}
