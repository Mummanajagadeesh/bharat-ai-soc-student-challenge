-- ==============================================================
-- Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.2 (64-bit)
-- Version: 2022.2
-- Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
-- ==============================================================
library ieee; 
use ieee.std_logic_1164.all; 
use ieee.std_logic_unsigned.all;

entity MVAU_hls_1_Matrix_Vector_Activate_Stream_Batch_p_ZL7threshs_13_ROM_AUTO_1R is 
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


architecture rtl of MVAU_hls_1_Matrix_Vector_Activate_Stream_Batch_p_ZL7threshs_13_ROM_AUTO_1R is 
 
signal address0_tmp : std_logic_vector(AddressWidth-1 downto 0); 

type mem_array is array (0 to AddressRange-1) of std_logic_vector (DataWidth-1 downto 0); 

signal mem0 : mem_array := (
    0 => "0100111110", 1 => "0101001111", 2 => "0110100010", 3 => "0011101101", 
    4 => "0011111010", 5 => "0111010110", 6 => "0101100100", 7 => "0101111010", 
    8 => "0100000110", 9 => "0101110110", 10 => "0100001111", 11 => "0110101100", 
    12 => "0110001100", 13 => "0101000011", 14 => "0101100011", 15 => "0110100101", 
    16 => "0101010110", 17 => "0100000110", 18 => "0100001100", 19 => "1011101011", 
    20 => "0100101010", 21 => "0111100001", 22 => "0011000010", 23 => "0101111111", 
    24 => "0011011010", 25 => "0111011110", 26 => "0101010110", 27 => "0101000110", 
    28 => "1000001011", 29 => "0100101001", 30 => "1000011110", 31 => "0100110100");



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

