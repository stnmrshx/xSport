CVE-2013-1763
=============

Bug di Sock_diag_handler

"Array index error in the __sock_diag_rcv_msg function in net/core/sock_diag.c in the Linux kernel before 3.7.10 allows local users to gain privileges via a large family value in a Netlink message"

POCnya ini cuma buat : 

Ubuntu 12.04.2 x86_64 kernel 3.5.0-23-generic<br />
Ubuntu 12.10 x86_64 kernel 3.5.0-17-generic<br />
Ubuntu 12.10 x86_64 kernel 3.7.0-7-generic<br />

Kalo mau ditambahin yo monggo silahken ditambahin, buat yang x86 saya ndak punya mesinnya, mesin x86 saya matek :)) paling ganti trampolinenya sama creds nya aja udah, trampolinenya ngambil dari push cred ajah, yaaaa standar null pointer dereference lah.

Kalo di Ubuntu 12.04.2 gak bisa di kompail (sock_diag.h nya gak ada gitu errornya) ente kompail di 12.10 aja soalnya buat yang 12.04.2 emang masih belom official di taruh. Cek nya di /usr/include/linux

Plis ya bok jangan di cengin :(