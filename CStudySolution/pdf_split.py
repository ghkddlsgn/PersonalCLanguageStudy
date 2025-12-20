import PyPDF2

def split_and_reorder_pdf(input_path, output_diploma_path, output_transcript_path):
    with open(input_path, 'rb') as infile:
        reader = PyPDF2.PdfReader(infile)
        
        # Page Index Mapping (0-based)
        # Original: 
        # 0: Apostille (Diploma)
        # 1: Apostille (Duplicate - Skip)
        # 2: Notary Cert (Diploma - No. 1635)
        # 3: Korean Diploma
        # 4: English Diploma
        # 5: Notary Cover (Diploma - No. 1635)
        # 6: Apostille (Transcript)
        # 7: Notary Cert (Transcript - No. 1634)
        # 8: Korean Transcript
        # 9: English Transcript
        # 10: Notary Cover (Transcript - No. 1634)

        # Desired Order: Apostille -> Cover -> Notary Cert -> English -> Korean
        
        # Diploma Order
        diploma_indices = [5,4,3,2,1] 
        diploma_writer = PyPDF2.PdfWriter()
        for idx in diploma_indices:
            diploma_writer.add_page(reader.pages[idx])
            
        with open(output_diploma_path, 'wb') as d_out:
            diploma_writer.write(d_out)

        # Transcript Order
        transcript_indices = [10,9,8,7,6]
        transcript_writer = PyPDF2.PdfWriter()
        for idx in transcript_indices:
            transcript_writer.add_page(reader.pages[idx])
            
        with open(output_transcript_path, 'wb') as t_out:
            transcript_writer.write(t_out)

# Execute the function
split_and_reorder_pdf(
    'CStudySolution/Diploma_transcript_uncleanedData.pdf', 
    'Bachelor_Degree_Certificate.pdf', 
    'Academic_Transcript.pdf'
)