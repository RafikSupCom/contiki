package se.sics.cooja;
public class LoRaConfig {


// =====================================================
// LoRa Airtime Parameters
// =====================================================
    
	
	public static boolean LORA_MODE = true;

    public static double LORA_DECAY = 300.0;

    //public static double LORA_T0 = 100.0;

    public static int LORA_SF = 7;

    public static double LORA_BW = 125.0;
	


// Coding Rate
// 1->4/5, 2->4/6, 3->4/7, 4->4/8
public static int LORA_CR = 1;

// Preamble length (symbols)
public static int LORA_PREAMBLE = 8;

// Explicit header
// 0 = explicit
// 1 = implicit
public static int LORA_H = 0;

// CRC enabled
// 0 = disabled
// 1 = enabled
public static int LORA_CRC = 1;

// Low Data Rate Optimization
// 0 = disabled
// 1 = enabled
public static int LORA_DE = 0;
	
	
	
	
	
	
	

    // =====================================================
    // MH-ADR PARAMETERS
    // =====================================================

    public static boolean MH_ADR = false;

    public static int DEFAULT_SF = 7;

    // =====================================================
    // RSSI MODEL
    // =====================================================

    public static double RSSI0 = -40.0;

    public static double RSSI_DECAY = 0.12;
	
	 // =====================================================
    // MH-ADR RSSI THRESHOLDS 
    // =====================================================

    public static int RSSI_SF7  = -90;
    public static int RSSI_SF8  = -95;
    public static int RSSI_SF9  = -100;
    public static int RSSI_SF10 = -105;
    public static int RSSI_SF11 = -110;
	
	
	
	
}