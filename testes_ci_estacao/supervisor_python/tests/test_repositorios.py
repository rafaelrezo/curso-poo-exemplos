from estacao.modelos import Leitura
from estacao.repositorios import RepositorioLeiturasMemoria, RepositorioLeiturasSqlite


def criar_leitura(tag: str = "LT-101", valor: float = 40.0) -> Leitura:
    return Leitura(
        timestamp="2026-06-09T10:00:00-03:00",
        tag=tag,
        valor=valor,
        unidade="%",
        status="operando",
    )


def test_repositorio_memoria_lista_por_tag():
    repositorio = RepositorioLeiturasMemoria()
    repositorio.salvar(criar_leitura(tag="LT-101", valor=40.0))
    repositorio.salvar(criar_leitura(tag="PT-201", valor=2.7))

    leituras = repositorio.listar_por_tag("LT-101")

    assert len(leituras) == 1
    assert leituras[0].tag == "LT-101"
    assert leituras[0].valor == 40.0


def test_repositorio_sqlite_salva_e_lista_por_tag(tmp_path):
    caminho_banco = tmp_path / "leituras_teste.db"
    repositorio = RepositorioLeiturasSqlite(str(caminho_banco))
    repositorio.inicializar()
    repositorio.salvar(criar_leitura(tag="LT-101", valor=40.0))
    repositorio.salvar(criar_leitura(tag="PT-201", valor=2.7))

    leituras = repositorio.listar_por_tag("PT-201")

    assert len(leituras) == 1
    assert leituras[0].tag == "PT-201"
    assert leituras[0].valor == 2.7

