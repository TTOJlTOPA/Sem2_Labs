.686
.model flat
.data
tmp dd 0
count dd 0
del dd 0
.code
Public _func1
_func1 proc
        push ebp
        mov ebp,esp
		mov ecx, [ebp + 8]
		mov esi, [ebp + 12]
	inc ecx
	mov ebx, 2
for_ :
	mov eax, ebx
	mov [esi], eax
	inc ebx
	add esi, 4
loop for_
	pop ebp
	ret 
_func1 endp

Public @func2@8
@func2@8 proc      
        ;mov edi, ecx
		mov esi, edx
	inc ecx
	mov ebx, 2
for_ :
	mov eax, ebx
	mov [esi], eax
	inc ebx
	add esi, 4
loop for_
	ret
@func2@8 endp

Public _func3@8
_func3@8 proc
        push ebp
        mov ebp,esp
		mov ecx, [ebp + 8]
		mov esi, [ebp + 12]
	inc ecx
	mov ebx, 2
for_ :
	mov eax, ebx
	mov [esi], eax
	inc ebx
	add esi, 4
loop for_
  pop ebp
  ret 8  
_func3@8 endp

end