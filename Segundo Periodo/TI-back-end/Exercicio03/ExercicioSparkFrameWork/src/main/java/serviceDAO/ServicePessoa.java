package serviceDAO;

import java.sql.Timestamp;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import modelo.Pessoa;

public class ServicePessoa {
	private Connection con;
	
	public ServicePessoa() {
		String url = "jdbc:postgresql://localhost:5432/Cadastrados";
		String user = "postgres";
		String senha = "senha123";
		try {
			con = DriverManager.getConnection(url,user,senha);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	public void add(Pessoa pessoa) {
		String sql = "INSERT INTO pessoas (nome, genero, telefone, data_nascimento, nacionalidade, estado_civil, cpf) VALUES (?, ?, ?, ?, ?, ?, ?)";
		try {
			PreparedStatement statemente = con.prepareStatement(sql);
			statemente.setString(1, pessoa.getNome());
			statemente.setString(2,pessoa.getGenero());
			statemente.setString(3,pessoa.getTelefone());
			statemente.setTimestamp(4,Timestamp.valueOf(pessoa.getDataNascionalidade()));
			statemente.setString(5,pessoa.getNacionalidade());
			statemente.setString(6,pessoa.getEstadoCivil());
			statemente.setString(7, pessoa.getCpf());
			
			statemente.executeUpdate();
            System.out.println("Registro adicionado");

		}catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	public Pessoa getInfoPessoa(String cpf) {
		String sql = "SELECT * FROM pessoas WHERE cpf = ?";
		Pessoa person = null;
		try {
			PreparedStatement statement = con.prepareStatement(sql);
			statement.setString(1, cpf);
			ResultSet resul = statement.executeQuery();
			if(resul.next()) {
				person = new Pessoa(resul.getString("cpf"),resul.getString("nome"),resul.getString("nacionalidade"),resul.getString("genero"),resul.getTimestamp("data_nascimento").toLocalDateTime(),resul.getString("telefone"),resul.getString("estado_civil"));
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		return person;
	}
	
	public void atualizarPessoa(Pessoa pessoa) {
	    String sql = "UPDATE pessoas SET nome = ?, nacionalidade = ?, genero = ?, data_nascimento = ?, telefone = ?, estado_civil = ? WHERE cpf = ?";
	    
	    try {
	        PreparedStatement statement = con.prepareStatement(sql);
	        
	        statement.setString(1, pessoa.getNome());
	        statement.setString(2, pessoa.getNacionalidade());
	        statement.setString(3, pessoa.getGenero());
	        statement.setTimestamp(4, Timestamp.valueOf(pessoa.getDataNascionalidade()));
	        statement.setString(5, pessoa.getTelefone());
	        statement.setString(6, pessoa.getEstadoCivil());
	        
	        statement.setString(7, pessoa.getCpf());
	        
	        int linhasAfetadas = statement.executeUpdate();
	        
	        if (linhasAfetadas > 0) {
	            System.out.println("Registro atualizado");
	        } else {
	            System.out.println("Nenhum registro foi atualizado.");
	        }
	        
	    } catch (Exception e) {
	        e.printStackTrace();
	    }
	}
	
	public void delete(String cpf) {
	    String sql = "DELETE FROM pessoas WHERE cpf = ?";
	    
	    try {
	        PreparedStatement statement = con.prepareStatement(sql);
	        statement.setString(1, cpf);
	        
	        int linhasAfetadas = statement.executeUpdate();
	        if (linhasAfetadas > 0) {
	            System.out.println("Registro excluído com sucesso.");
	        } else {
	            System.out.println("Nenhum registro foi excluído (CPF não encontrado).");
	        }
	        
	    } catch (Exception e) {
	        e.printStackTrace();
	    }
	}

	
	public void close() {
		try {
			con.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
	
}
