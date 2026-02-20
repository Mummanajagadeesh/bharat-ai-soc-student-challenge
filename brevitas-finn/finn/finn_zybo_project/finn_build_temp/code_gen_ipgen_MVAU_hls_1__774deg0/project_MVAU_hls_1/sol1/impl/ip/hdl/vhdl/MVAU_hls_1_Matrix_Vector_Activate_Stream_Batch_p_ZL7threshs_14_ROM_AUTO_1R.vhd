-- ==============================================================
-- Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.2 (64-bit)
-- Version: 2022.2
-- Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
-- ==============================================================
library ieee; 
use ieee.std_logic_1164.all; 
use ieee.std_logic_unsigned.all;

entity MVAU_hls_1_Matrix_Vector_Activate_Stream_Batch_p_ZL7threshs_14_ROM_AUTO_1R is 
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


architecture rtl of MVAU_hls_1_Matrix_Vector_Activate_Stream_Batch_p_ZL7threshs_14_ROM_AUTO_1R is 
 
signal address0_tmp : std_logic_vector(AddressWidth-1 downto 0); 

type mem_array is array (0 to AddressRange-1) of std_logic_vector (DataWidth-1 downto 0); 

signal mem0 : mem_array := (
    0 => "0101010001", 1 => "0101100011", 2 => "0110111111", 3 => "0100001110", 
    4 => "0100010001", 5 => "0111110011", 6 => "0101111110", 7 => "0110010111", 
    8 => "0100100110", 9 => "0110010010", 10 => "0100101001", 11 => "0111000110", 
    12 => "0110100111", 13 => "0101011010", 14 => "0101111100", 15 => "0111000000", 
    16 => "0101110101", 17 => "0100011001", 18 => "0100100101", 19 => "1100001010", 
    20 => "0100111110", 21 => "0111111101", 22 => "0011100011", 23 => "0110011010", 
    24 => "0011101110", 25 => "0111110110", 26 => "0101101100", 27 => "0101011110", 
    28 => "1000100101", 29 => "0101000001", 30 => "1000111011", 31 => "0101001010");



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

