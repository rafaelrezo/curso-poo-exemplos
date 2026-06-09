from modelos import Leitura
from repositorios import RepositorioLeituras, RepositorioLeiturasMemoria


def montar_tabela_leituras(repositorio: RepositorioLeituras) -> list[dict]:
    leituras = repositorio.listar_todas()
    return [leitura.__dict__ for leitura in leituras]


def main() -> None:
    repositorio = RepositorioLeiturasMemoria()

    repositorio.salvar(Leitura(
        timestamp="2026-06-09T10:00:00-03:00",
        tag="LT-101",
        valor=42.0,
        unidade="%",
        status="operando",
    ))

    repositorio.salvar(Leitura(
        timestamp="2026-06-09T10:01:00-03:00",
        tag="PT-201",
        valor=2.7,
        unidade="bar",
        status="operando",
    ))

    for linha in montar_tabela_leituras(repositorio):
        print(linha)


if __name__ == "__main__":
    main()
