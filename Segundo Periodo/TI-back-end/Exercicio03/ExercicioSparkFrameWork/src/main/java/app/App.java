package app;

import static spark.Spark.*;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

import modelo.Pessoa;
import serviceDAO.ServicePessoa;

class App {
	public static void main(String[] args) {
		port(8080);
		staticFileLocation("/public");
		get("/", (req,res) -> {
			return null;
		});
		
		post("/produto", (req,res) -> {
			String nome = req.queryParams("nome");
			String cpf = req.queryParams("cpf");
			String naciona = req.queryParams("nacionalidade");
			String genero = req.queryParams("genero");
			String telefone = req.queryParams("telefone");
			String estadoCivil = req.queryParams("estado-civil");
			String datanasc = req.queryParams("data-nascimento");
			
			
			System.out.println(nome + " " + cpf + " " + naciona + " " + genero + " " + telefone + " " + estadoCivil + " " + datanasc);

			DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd'T'HH:mm:ss");
			LocalDateTime dataNascimento = LocalDateTime.parse(datanasc, formatter);
			
			Pessoa pessoa = new Pessoa(cpf,nome,naciona,genero,dataNascimento,telefone,estadoCivil);
			ServicePessoa service = new ServicePessoa();
			service.add(pessoa);
			
			return null;
		});
	}
}
