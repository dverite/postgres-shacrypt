select sha512_crypt('Hello world!', '$6$saltstring');
select sha512_crypt('Hello world!', '$6$rounds=10000$saltstringsaltstring');
select sha512_crypt('This is just a test', '$6$rounds=5000$toolongsaltstring');
select sha512_crypt('a very much longer text to encrypt.  This one even stretches over morethan one line.', '$6$rounds=1400$anotherlongsaltstring');
select sha512_crypt('we have a short salt string but not a short password', '$6$rounds=77777$short');
select sha512_crypt('a short string', '$6$rounds=123456$asaltof16chars..');
select sha512_crypt('the minimum number is still observed', '$6$rounds=10$roundstoolow');
