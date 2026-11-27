# Como rodar Make File

## 1. Instalar o WSL

> wsl --install -d Ubuntu

### verifica o estado do WSL

> wsl --status

## 2. Instalar as ferramentas de compilação

>sudo apt update
>sudo apt install -y build-essential

### Verifique as versões:
>gcc --version
>make --version

## 3. Acessar o projeto no disco Z:

### No Win
> seu-disco:\seu-diretorio\seu-projeto
### exemplo:
Z:\repositorios\BIO-OBSW
### no WSL corresponde a 
> /mnt/seu-disco/seu-diretorio/seu-projeto

### exemplo:
> cd /mnt/z/repositorios/BIO-OBSW/OBSW

# 4. Compilar

### faz o makeFile gerar a compilação
> make

### descarta a compilação
> make clean

## Ou

> make clean && make

# 6. Verificar o executável

> ls -l edc
> file edc

# 7. Executar 

> ./(seu arquivo)

# 8. fluxo completo

> cd /mnt/z/repositorios/BIO-OBSW/OBSW
> sudo apt update
> sudo apt install -y build-essential
> make clean
> make
> ./edc

# 9. Testes 
### OBS: Testes do OBSW Geral

Na raiz do repositório, rode todos os testes:

```bash
make -C OBSW test