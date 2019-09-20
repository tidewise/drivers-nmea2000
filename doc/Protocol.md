# N2K encoding in a CAN frame

## CAN ID Format

| Offset (bits) | Length (bits) | Interpretation         |
|--------|---------------|------------------------|
| 0      | 8             | Source                 |
| 8      | 8             | Destination or PGN LSB |
| 16     | 8             | PGN Midddle Byte       |
| 24     | 2             | PGN High bits          |
| 26     | 3             | Priority               |

The second byte is either the destination or the PGN least significant
byte. In the former case, the PGN middle byte will be lower than 240
and the PGN middle byte is zero (PDU1 format). In the latter case, PGN
middle byte is higher than 240 and the message is broadcast.

Note that this description allocates two bits for PGN high bits. The J1939
standard on top of which NMEA2000 is built uses only one, describing the
second as an "extended page" which must be set to zero. Keeping it in the PGN
should therefore have no effect.

## Fast Packet Reassembly

Fast packet is the most common way to transmit data bigger than 8 bytes
on a NMEA2000 network. Many libraries assume that a PGN of size bigger
than 8 will use the NMEA2000 Fast Packet protocol.

The first frame of a fast packet stream encodes a sequence identifier
which identifies the sequence, and the sequence length. The payload is as
follows

| Offset | Length (bits) | Interpretation         |
|--------|---------------|------------------------|
| 0, bit 0 | 5 bits      | Index in sequence (zero for first packet) |
| 0, bit 5 | 3 bits      | Sequence Identifier |
| 1 | 1      | Length of sequence |
| 2 | 6      | First message bytes |

Subsequent frames will repeat the sequence identifier and have an updated
sequence index, but won't repeat the sequence length.

| Offset | Length (bits) | Interpretation         |
|--------|---------------|------------------------|
| 0, bit 0 | 5 bits      | Index in sequence (zero for first packet) |
| 0, bit 5 | 3 bits      | Sequence Identifier |
| 1 | up to 7      | Message bytes |

