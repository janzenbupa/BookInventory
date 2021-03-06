USE [BookInventory]
GO
/****** Object:  StoredProcedure [dbo].[InsertAuthor]    Script Date: 8/15/2021 7:03:13 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
-- =============================================
-- Author:		<Author,,Name>
-- Create date: <Create Date,,>
-- Description:	<Description,,>
-- =============================================
ALTER PROCEDURE [dbo].[InsertAuthor]
	-- Add the parameters for the stored procedure here
	@firstName nvarchar(35),
	@lastName nvarchar(35)
AS
BEGIN
	BEGIN TRANSACTION
	BEGIN TRY
		INSERT INTO [dbo].[Authors](
			FirstName,
			LastName
		)
		VALUES(
			@firstName,
			@lastName
		)
		IF @@TRANCOUNT != 1
		BEGIN
			ROLLBACK TRANSACTION
		END
		ELSE
		BEGIN
			COMMIT TRANSACTION 
		END
	END TRY
	BEGIN CATCH
		IF @@TRANCOUNT != 0
		BEGIN
			ROLLBACK TRANSACTION
		END
	END CATCH
END
