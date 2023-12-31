// #include "wave-setup.h"

// namespace ns3
// {

// WaveSetup::WaveSetup(){}
// WaveSetup::~WaveSetup () {}

// NetDeviceContainer WaveSetup::ConfigureDevices (NodeContainer& nodes, vector<vector<DisplayObject>*> objContainers)
// {
//   /*
//     Setting up WAVE devices. With PHY & MAC using default settings. 
//   */
//   YansWifiChannelHelper waveChannel = YansWifiChannelHelper();
//   waveChannel.SetPropagationDelay ("ns3::ConstantSpeedPropagationDelayModel");
//   waveChannel.AddPropagationLoss ("ns3::FriisPropagationLossModel", "Frequency", DoubleValue(5.9e9));
//   YansWavePhyHelper wavePhy =  YansWavePhyHelper::Default ();
//   Ptr<YansWifiChannel> channel = waveChannel.Create();
//   wavePhy.SetChannel (channel);
//   uint32_t channelID = channel->GetId();
//   wavePhy.Set("Frequency", UintegerValue(5900));
//   std::string channelTuple = "{" + std::to_string(channelID) + ", " + std::to_string(10) + ", BAND_5GHZ, 0}";
//   wavePhy.Set("ChannelSettings", StringValue(channelTuple));

//   wavePhy.SetPcapDataLinkType (WifiPhyHelper::DLT_IEEE802_11_RADIO);
//   //Setup up MAC
//   QosWaveMacHelper waveMac = QosWaveMacHelper::Default ();
//   WaveHelper waveHelper = WaveHelper::Default ();

//   waveHelper.SetRemoteStationManager ("ns3::ConstantRateWifiManager",
//   						"DataMode", StringValue ("OfdmRate3MbpsBW10MHz"	),
//   						"ControlMode",StringValue ("OfdmRate1MbpsBW10MHz"),
//   						"NonUnicastMode", StringValue ("OfdmRate6MbpsBW10MHz"),
//               "MaxSlrc", UintegerValue(2),
//               "MaxSsrc", UintegerValue(2));

//   NetDeviceContainer devices = waveHelper.Install (wavePhy, waveMac, nodes);



//   for(uint32_t iNode=0;iNode<devices.GetN();iNode++){
//     Ptr<WaveNetDevice> node = DynamicCast<WaveNetDevice> (devices.Get(iNode));
//     // Change AIFs[1] = 3; AIFs[0] = 2; cw_min = 15; cw_max = 31
//     Ptr<OcbWifiMac> nodeMac = node->GetMac(178);
//     Ptr<QosTxop> viTxop = nodeMac->GetQosTxop(AC_VI);
//     Ptr<QosTxop> voTxop = nodeMac->GetQosTxop(AC_VO);
//     viTxop->TraceConnect("BackOffTrace", "BackOffTrace", ns3::MakeBoundCallback(&MacTxBackOffTrace, objContainers[MACTXBACKOFFNUM]));
//     viTxop->SetMinCw(15);
//     viTxop->SetMaxCw(31);
//     viTxop->SetAifsn(3);
//     voTxop->SetAifsn(2);

//     Ptr<WifiPhy> nodePhy = node->GetPhy(0);
//     // Time sifs = Time::FromInteger(32, Time::US);
//     // nodePhy->SetSifs(sifs);
//     // Time slot = Time::FromInteger(13, Time::US);
//     // nodePhy->SetSlot(slot);

//     // Set Tx Power to 500m
//     nodePhy->SetTxPowerStart(19.9);
//     nodePhy->SetTxPowerEnd(19.9);
//     // Set CSR to 700m
//     nodePhy->SetCcaEdThreshold(-84.87);
//     // Set RX Sensitivity
//     nodePhy->SetRxSensitivity(-84.87);
//   }

//   return devices;
// }

// }