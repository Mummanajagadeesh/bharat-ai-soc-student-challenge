-- ==============================================================
-- Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.2 (64-bit)
-- Version: 2022.2
-- Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
-- ==============================================================
library ieee; 
use ieee.std_logic_1164.all; 
use ieee.std_logic_unsigned.all;

entity MVAU_hls_1_Matrix_Vector_Activate_Stream_Batch_p_ZL7threshs_12_ROM_AUTO_1R is 
    generic(
             DataWidth     : integer := 10; 
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


architecture rtl of MVAU_hls_1_Matrix_Vector_Activate_Stream_Batch_p_ZL7threshs_12_ROM_AUTO_1R is 
 
signal address0_tmp : std_logic_vector(AddressWidth-1 downto 0); 

type mem_array is array (0 to AddressRange-1) of std_logic_vector (DataWidth-1 downto 0); 

signal mem0 : mem_array := (
    0 => "0100101011", 1 => "0100111011", 2 => "0110000101", 3 => "0011001011", 
    4 => "0011100100", 5 => "0110111001", 6 => "0101001001", 7 => "0101011101", 
    8 => "0011100111", 9 => "0101011010", 10 => "0011110101", 11 => "0110010010", 
    12 => "0101110000", 13 => "0100101101", 14 => "0101001001", 15 => "0110001010", 
    16 => "0100110111", 17 => "0011110100", 18 => "0011110011", 19 => "1011001100", 
    20 => "0100010110", 21 => "0111000101", 22 => "0010100000", 23 => "0101100101", 
    24 => "0011000101", 25 => "0111000110", 26 => "0100111111", 27 => "0100101110", 
    28 => "0111110001", 29 => "0100010010", 30 => "1000000000", 31 => "0100011101");



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

