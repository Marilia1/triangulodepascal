#!/bin/bash
{ 
file1=resultado.txt
file2=resultesperado.txt
file3=teste.txt
file4=resultscript.txt
	rm "$file1" || true
	rm "$file4" || true
	(./triangulodepascal < $file3) >> $file1
	if cmp -s "$file1" "$file2"
	then
	   echo "The files match" >> $file4
	else
	   echo "The files are different" >> $file4
	fi
} 
