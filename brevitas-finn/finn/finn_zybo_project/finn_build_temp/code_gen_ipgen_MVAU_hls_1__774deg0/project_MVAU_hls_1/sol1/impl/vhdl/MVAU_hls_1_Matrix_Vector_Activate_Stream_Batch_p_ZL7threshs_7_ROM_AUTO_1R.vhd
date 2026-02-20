-- ==============================================================
-- Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.2 (64-bit)
-- Version: 2022.2
-- Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
-- ==============================================================
library ieee; 
use ieee.std_logic_1164.all; 
use ieee.std_logic_unsigned.all;

entity MVAU_hls_1_Matrix_Vector_Activate_Stream_Batch_p_ZL7threshs_7_ROM_AUTO_1R is 
    generic(
             DataWidth     : integer := 11; 
             AddressWidth     : integer := 5; 
             AddressRange    : integer := 32
    ); 
    port (
 
          address0        : in std_logic_vector(AddressWidth-1 downto 0); 
          ce0             : in std_logic; 
          q0              : out std_logic_vector(DataWidth-1 downto 0);

          reset               : in std_logic;
          clk                 : in std_logic
    ); 
end entity; 


architecture rtl of MVAU_hls_1_Matrix_Vector_Activate_Stream_Batch_p_ZL7threshs_7_ROM_AUTO_1R is 
 
signal address0_tmp : std_logic_vector(AddressWidth-1 downto 0); 

type mem_array is array (0 to AddressRange-1) of std_logic_vector (DataWidth-1 downto 0); 

signal mem0 : mem_array := (
    0 => "00011001101", 1 => "00011010101", 2 => "00011110011", 3 => "00000100101", 
    4 => "00001110100", 5 => "00100101000", 6 => "00011000100", 7 => "00011001011", 
    8 => "00001001001", 9 => "00011001101", 10 => "00001110101", 11 => "00100001111", 
    12 => "00011101000", 13 => "00010111010", 14 => "00011001010", 15 => "00100000011", 
    16 => "00010011001", 17 => "00010010111", 18 => "00001110101", 19 => "01000110010", 
    20 => "00010110100", 21 => "00100111001", 22 => "11111111000", 23 => "00011100010", 
    24 => "00001100000", 25 => "00101001111", 26 => "00011001111", 27 => "00010110011", 
    28 => "00101110000", 29 => "00010011010", 30 => "00101101010", 31 => "00010101100");



begin 

 
memory_access_guard_0: process (address0) 
begin
      address0_tmp <= address0;
--synthesis translate_off
      if (CONV_INTEGER(address0) > AddressRange-1) then
           address0_tmp <= (others => '0');
      else 
           address0_tmp <= address0;
      end if;
--synthesis translate_on
end process;

p_rom_access: process (clk)  
begin 
    if (clk'event and clk = '1') then
 
        if (ce0 = '1') then  
            q0 <= mem0(CONV_INTEGER(address0_tmp)); 
        end if;

end if;
end process;

end rtl;

